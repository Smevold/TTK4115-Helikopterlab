"""Kompakte figurer til Lab 3-rapporten, i samme stil som plot_alle.py.

Kjør fra repo-rota:  uv run --project plotting python plotting/plot_lab3_report.py
Lager:
  HelikopterParakopter/Lab3/Report_ObserverPoles_Compare.pdf  (encoder: pitch, elevation, travel for tre kjøringer)
  HelikopterParakopter/Lab3/Report_ElevationInFlight.pdf      (elevasjon fra akselerometeret mot encoder i flyvning)
"""
import os
import sys
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plot_alle import load_mat, FORMATER, STIL, CM, K  # noqa: E402

LAB3 = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "HelikopterParakopter", "Lab3")

# Kjøringene som sammenlignes.
RUNS = [
    ("2_3_3_FirstLQRRun_WithoutEstimator.mat", "No observer", "#7f7f7f"),
    ("2_3_3_PolesAtneg8_WithPush.mat",        r"Poles $-6,\dots,-10$", "#0b3c8c"),
    ("2_3_3_LambdasExtremelyToTheLeft.mat",   r"Poles $\approx -100$", "#d62728"),
]
T_MAX = 55  # [s] felles tidsvindu (kortest av kjøringene)

f = FORMATER["hel"]
rc = {"font.size": f["font"], "axes.titlesize": f["font"], "axes.labelsize": f["font"],
      "xtick.labelsize": f["font"], "ytick.labelsize": f["font"], "legend.fontsize": f["font"]}


def legend_over(fig, ax, ncol):
    leg = fig.legend(*ax.get_legend_handles_labels(), loc="outside upper center", ncol=ncol,
                     frameon=False, handlelength=1.6, handletextpad=0.4, columnspacing=1.2)
    for line in leg.get_lines():
        line.set_linewidth(2.2)
        line.set_alpha(1)


with plt.rc_context(rc):
    # ---------- Figur 1: tre kjøringer oppå hverandre (bare encoder = fasit) ----------
    paneler = [("Pitch [rad]", K["pitch"], False), ("Elevation [rad]", K["elev"], False),
               ("Travel [rad]", K["travel"], True)]
    fig, axes = plt.subplots(3, 1, figsize=(f["bredde"] * CM, (3 * 3.2 + 1.8) * CM), sharex=True,
                             layout="constrained")
    for fname, label, farge in RUNS:
        t, V = load_mat(os.path.join(LAB3, fname))
        k = (t >= 0.05) & (t <= T_MAX)
        for ax, (tittel, kol, fra_null) in zip(axes, paneler):
            y = V[k, kol] - (V[k, kol][0] if fra_null else 0)
            ax.plot(t[k], y, color=farge, lw=1.2, alpha=0.9, label=label)
    for ax, (tittel, _, _) in zip(axes, paneler):
        ax.set_title(tittel, loc="left")
        ax.grid(True, alpha=0.3)
    axes[-1].set_xlim(0, T_MAX)
    fig.supxlabel("Time [s]", fontsize=f["font"])
    legend_over(fig, axes[0], ncol=3)
    fig.savefig(os.path.join(LAB3, "Report_ObserverPoles_Compare.pdf"))
    plt.close(fig)

    # ---------- Figur 2: elevasjon fra akselerometeret i flyvning ----------
    t, V = load_mat(os.path.join(LAB3, RUNS[1][0]))
    k = (t >= 20) & (t <= 30)
    fig, ax = plt.subplots(figsize=(f["bredde"] * CM, 5.5 * CM), layout="constrained")
    acc, enc = STIL["Accelerometer"], STIL["Encoder"]
    ax.plot(t[k], V[k, K["e_acc"]], color=acc["colors"][0], lw=0.8, alpha=acc["alpha"], label="Accelerometer")
    ax.plot(t[k], V[k, K["elev"]], color=enc["colors"][0], lw=enc["lw"], label="Encoder")
    ax.set_title("Elevation [rad]", loc="left")
    ax.set_xlim(20, 30)
    ax.grid(True, alpha=0.3)
    fig.supxlabel("Time [s]", fontsize=f["font"])
    legend_over(fig, ax, ncol=2)
    fig.savefig(os.path.join(LAB3, "Report_ElevationInFlight.pdf"))
    plt.close(fig)

print("Lagret Report_ObserverPoles_Compare.pdf og Report_ElevationInFlight.pdf i", LAB3)
