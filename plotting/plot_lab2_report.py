"""Sammenligningsfigurer til Lab 2 i rapporten, i samme stil som plot_alle.py.

Hver figur viser to tester ved siden av hverandre:
    pitch  (test a) | pitch  (test b)
    ė      (test a) | ė      (test b)
Radene har felles y-akse, så testene kan sammenlignes direkte. Hver kolonne har sin egen
tidsakse, fordi testene er ulikt lange og referansen ikke endrer seg likt.

Kjør fra repo-rota:  uv run --project plotting python plotting/plot_lab2_report.py
Lager HelikopterParakopter/Figurer_rapport/Fig_L2_Test<n>.pdf
"""
import os
import sys
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plot_alle import load_mat, FORMATER, STIL, CM, K  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(REPO, "HelikopterParakopter")
UT = os.path.join(DATA, "Figurer_rapport")

# (figurnavn, [(fil, kolonnetittel), ...])
FIGURER = [
    ("Fig_L2_Test1", [("Lab_2_1/q_2_10-x_0.5.mat", r"Test 1: $q_2 = 10$")]),
    ("Fig_L2_Test2", [("Lab_2_1/q_1_10_q_2_q_3_r_1_5_r_2_1.mat", r"Test 2.1: $q_1 = 10$, $r_2 = 1$"),
                      ("Lab_2_1/q_1_1_q_2_q_3_r_1_5_r_2_10.mat", r"Test 2.2: $q_1 = 1$, $r_2 = 10$")]),
    ("Fig_L2_Test3", [("Lab_2_1/q1=q2=r2=5_q3=10_r2=1.mat", r"Test 3.1: $q_3 = 10$, $r_1 = 1$"),
                      ("Lab_2_1/q1=q2=r2=5_q3=1_r2=10.mat", r"Test 3.2: $q_3 = 1$, $r_1 = 10$")]),
    ("Fig_L2_Test4", [("Lab_2_1/q1=3_q2=1_q3=6_r1=0.5_r2=0.5.mat", r"Test 4.1: $r_1 = r_2 = 0.5$"),
                      ("Lab_2_1/q1=3_q2=1_q3=6_r1=50_r2=50.mat", r"Test 4.2: $r_1 = r_2 = 50$")]),
    ("Fig_L2_Test5", [("Lab_2_2/q1=3_q2=1_q3=6_q4=20_q5=4_r1=3_r2=6.mat", r"Test 5.1: $q_4 = 20$, $q_5 = 4$"),
                      ("Lab_2_2/q1=3_q2=1_q3=6_q4=4_q5=20_r1=3_r2=6.mat", r"Test 5.2: $q_4 = 4$, $q_5 = 20$")]),
]

f = FORMATER["rutenett"]
rc = {"font.size": f["font"], "axes.titlesize": f["font"], "axes.labelsize": f["font"],
      "xtick.labelsize": f["font"], "ytick.labelsize": f["font"], "legend.fontsize": f["font"]}
RADER = [("Pitch [rad]", K["pitch"], K["joy_x"]), ("Elevation rate [rad/s]", K["elev_rate"], K["joy_y"])]


def referanse(navn, t, V, kol):
    """Joystick-referansen hvis den er logget, ellers steget fra filnavnet (0.5 ved t = 5 s)."""
    if V.shape[1] > kol:
        return V[:, kol]
    steg = 0.5 * (t >= 5.0)
    if (kol == K["joy_x"] and "-x_" in navn) or (kol == K["joy_y"] and "-y_" in navn):
        return steg
    return None


def plot_figur(figurnavn, tester):
    enc, ref = STIL["Encoder"], STIL["Reference"]
    n = len(tester)
    alene = n == 1  # én test: pitch | ė ved siden av hverandre i stedet for under hverandre
    if alene:
        fig, axes = plt.subplots(1, 2, figsize=(f["bredde"] * CM, (2.9 + 2.0) * CM), sharex=True,
                                 layout="constrained", squeeze=False)
    else:
        fig, axes = plt.subplots(2, n, figsize=(f["bredde"] * CM, (2 * 3.6 + 2.2) * CM), sharex="col",
                                 sharey="row", layout="constrained", squeeze=False)
    for j, (fil, tittel) in enumerate(tester):
        t, V = load_mat(os.path.join(DATA, fil))
        navn = os.path.basename(fil)
        for i, (ylabel, kol, refkol) in enumerate(RADER):
            ax = axes[0, i] if alene else axes[i, j]
            r = referanse(navn, t, V, refkol)
            if r is not None:
                ax.plot(t, r, color=ref["colors"][0], lw=ref["lw"], ls=ref["ls"], alpha=ref["alpha"],
                        zorder=ref["z"], label="Reference")
            ax.plot(t, V[:, kol], color=enc["colors"][0], lw=1.0, alpha=enc["alpha"], zorder=enc["z"],
                    label="Encoder")
            ax.grid(True, alpha=0.3)
            ax.set_xlim(t[0], t[-1])
            if not alene:  # lik y-skala i alle parfigurene (referansen går til ±1)
                ax.set_ylim(-1.1, 1.1)
                ax.set_yticks([-1, -0.5, 0, 0.5, 1])
            if alene:
                ax.set_title(ylabel)
            elif j == 0:
                ax.set_ylabel(ylabel)
        if not alene:
            axes[0, j].set_title(tittel)
    fig.supxlabel("Time [s]", fontsize=f["font"])
    handles, labels = axes[0, 0].get_legend_handles_labels()
    rekkefolge = sorted(range(len(labels)), key=lambda k: ["Encoder", "Reference"].index(labels[k]))
    leg = fig.legend([handles[k] for k in rekkefolge], [labels[k] for k in rekkefolge],
                     loc="outside upper center", ncol=2, frameon=False)
    for line in leg.get_lines():
        line.set_linewidth(2.2)
        line.set_alpha(1)
    os.makedirs(UT, exist_ok=True)
    sti = os.path.join(UT, figurnavn + ".pdf")
    fig.savefig(sti)
    plt.close(fig)
    print("Lagret", os.path.relpath(sti, REPO))


with plt.rc_context(rc):
    for figurnavn, tester in FIGURER:
        plot_figur(figurnavn, tester)
