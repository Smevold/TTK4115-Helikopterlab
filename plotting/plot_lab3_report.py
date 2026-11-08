"""Kompakte figurer til Lab 3-rapporten.

Kjør fra repo-rota:  uv run --project plotting python plotting/plot_lab3_report.py
Lager:
  HelikopterParakopter/Lab3/Report_ObserverPoles_Compare.pdf  (pitch + travel, to kjøringer oppå hverandre)
  HelikopterParakopter/Lab3/Report_ElevationInFlight.pdf      (akselerometer-elevasjon vs encoder i flyvning)
"""
import os
import numpy as np
import scipy.io as sio
import matplotlib.pyplot as plt

LAB3 = "HelikopterParakopter/Lab3"

# ---- FYLL INN: hvilke poler som ble brukt i hver kjøring ----
RUNS = [
    ("2_3_3_PolesAtneg8_WithPush.mat",      r"Observer poles $\{-6,\dots,-10\}$"),
    ("2_3_3_LambdasExtremelyToTheLeft.mat", r"Observer poles far left [FYLL INN]"),
]
T_MAX = 55  # [s] felles tidsvindu

CM = 1 / 2.54
plt.rcParams.update({"font.size": 11})


def load(path):
    d = sio.loadmat(path)
    if "simout" in d:
        s = d["simout"][0, 0]
        return np.ravel(s["time"]), s["signals"][0, 0]["values"]
    a = d["ans"]
    return a[0], a[1:].T


# Kolonner (samme rekkefølge som Mux i Simulink)
TRAVEL, PITCH, ELEV, IMU_ELEV = 0, 2, 4, 15

# ---------- Figur 1: to kjøringer oppå hverandre ----------
fig, axes = plt.subplots(2, 1, figsize=(16 * CM, 9 * CM), sharex=True, layout="constrained")
colors = ["#0b3c8c", "#d62728"]
for (fname, label), c in zip(RUNS, colors):
    t, v = load(os.path.join(LAB3, fname))
    k = (t >= 0.05) & (t <= T_MAX)
    axes[0].plot(t[k], v[k, PITCH], color=c, lw=1.0, label=label)
    axes[1].plot(t[k], v[k, TRAVEL] - v[k, TRAVEL][0], color=c, lw=1.3, label=label)
axes[0].set_ylabel("Pitch [rad]")
axes[1].set_ylabel("Travel [rad]")
axes[1].set_xlabel("Time [s]")
for ax in axes:
    ax.grid(True, alpha=0.3)
leg = fig.legend(*axes[0].get_legend_handles_labels(), loc="outside upper center", ncol=2, frameon=False)
for line in leg.get_lines():
    line.set_linewidth(2.5)
axes[1].set_xlim(0, T_MAX)
fig.savefig(os.path.join(LAB3, "Report_ObserverPoles_Compare.pdf"))

# ---------- Figur 2: akselerometer-elevasjon i flyvning ----------
t, v = load(os.path.join(LAB3, RUNS[0][0]))
k = (t >= 20) & (t <= 30)
fig, ax = plt.subplots(figsize=(16 * CM, 5.5 * CM), layout="constrained")
ax.plot(t[k], v[k, IMU_ELEV], color="#d62728", lw=0.6, alpha=0.8, label="Accelerometer")
ax.plot(t[k], v[k, ELEV], color="#0b3c8c", lw=1.5, label="Encoder")
ax.set_ylabel("Elevation [rad]")
ax.set_xlabel("Time [s]")
ax.set_xlim(20, 30)
ax.grid(True, alpha=0.3)
leg = fig.legend(*ax.get_legend_handles_labels(), loc="outside upper center", ncol=2, frameon=False)
for line in leg.get_lines():
    line.set_linewidth(2.5)
fig.savefig(os.path.join(LAB3, "Report_ElevationInFlight.pdf"))
print("Lagret figurene i", LAB3)
