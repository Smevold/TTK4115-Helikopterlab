"""Sammenligningsfigurer til Lab 1 i rapporten, i samme stil som plot_alle.py og plot_lab2_report.py.

Hver figur viser pitch for to forsøk ved siden av hverandre, de første 10 s av hvert forsøk.
Referansen p_c er ikke logget i Lab 1, så bare responsen vises.
Alle stabile forsøk har samme y-skala. Det ustabile forsøket går til ±1.8 rad og får egen skala.

Kjør fra repo-rota:  uv run --project plotting python plotting/plot_lab1_report.py
Lager HelikopterParakopter/Figurer_rapport/Fig_L1_Poles<n>.pdf
"""
import os
import sys
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plot_alle import load_mat, FORMATER, STIL, CM, K  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(REPO, "HelikopterParakopter", "Lab1")
UT = os.path.join(REPO, "HelikopterParakopter", "Figurer_rapport")

YLIM_STABIL = (-0.8, 0.8)
YLIM_USTABIL = (-2.0, 2.0)
T_MAKS = 10.0  # [s] samme tidsakse i alle panelene, så det er lett å sammenligne hvor raskt de responderer

# (figurnavn, [(fil, kolonnetittel, ustabil), ...]). Titlene er polene forsøket ble kjørt FOR.
# Fordi K_pp og K_pd var byttet om, ble de faktiske polene andre (se bildeteksten i rapporten).
FIGURER = [
    ("Fig_L1_Poles1", [("verdier_lab_1_v05.mat", r"$\lambda_{1,2} = -0.5$", False),
                       ("verdier_lab_1_v1.mat", r"$\lambda_{1,2} = -1$", False)]),
    ("Fig_L1_Poles2", [("verdier_lab_1_v2.mat", r"$\lambda_{1,2} = -2$", False),
                       ("lab1_ren_imaginær.mat", r"$\lambda_{1,2} = \pm 3j$", False)]),
    ("Fig_L1_Poles3", [("lab1_complex_conjugat.mat", r"$\lambda_{1,2} = -3 \pm 2j$", False),
                       ("lab1 _1_-2.mat", r"$\lambda_1 = 1,\ \lambda_2 = -2$", True)]),
]

f = FORMATER["rutenett"]
rc = {"font.size": f["font"], "axes.titlesize": f["font"], "axes.labelsize": f["font"],
      "xtick.labelsize": f["font"], "ytick.labelsize": f["font"], "legend.fontsize": f["font"]}


def plot_figur(figurnavn, forsok):
    enc = STIL["Encoder"]
    fig, axes = plt.subplots(1, len(forsok), figsize=(f["bredde"] * CM, 4.6 * CM), layout="constrained",
                             squeeze=False)
    for j, (fil, tittel, ustabil) in enumerate(forsok):
        t, V = load_mat(os.path.join(DATA, fil))
        ax = axes[0, j]
        k = t <= T_MAKS
        ax.plot(t[k], V[k, K["pitch"]], color=enc["colors"][0], lw=1.2, alpha=0.9)
        ax.set_xlim(0, T_MAKS)
        ax.set_ylim(*(YLIM_USTABIL if ustabil else YLIM_STABIL))
        ax.grid(True, alpha=0.3)
        ax.set_title(tittel)
        if j == 0:
            ax.set_ylabel("Pitch [rad]")
    fig.supxlabel("Time [s]", fontsize=f["font"])
    os.makedirs(UT, exist_ok=True)
    sti = os.path.join(UT, figurnavn + ".pdf")
    fig.savefig(sti)
    plt.close(fig)
    print("Lagret", os.path.relpath(sti, REPO))


with plt.rc_context(rc):
    for figurnavn, forsok in FIGURER:
        plot_figur(figurnavn, forsok)
