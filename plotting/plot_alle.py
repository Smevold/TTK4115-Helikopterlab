"""Lager rapportklare PDF-plott av ALLE .mat-filene i HelikopterParakopter/.

Kjør fra repo-roten (eller hvor som helst):
    python plotting/plot_alle.py                 # alle filer
    python plotting/plot_alle.py Lab3 2_4_2      # bare filer der stien inneholder "Lab3" eller "2_4_2"

PDF-en lagres ved siden av .mat-filen, med samme navn.

Hva som plottes bestemmes av labben (mappa) og hvilke signaler som finnes i filen:
  Lab 1    PD-regulering av pitch (polplassering)   -> pitch og pitch rate              (halv bredde)
  Lab 2    LQR (+ integralvirkning)                 -> sporing av p_c og ė_c            (halv bredde for steg, hel for joystick)
  Lab 3    IMU og Luenberger-observer               -> encoder mot gyro/akselerometer   (halv bredde for håndtester, hel ellers)
  Lab 4    Kalmanfilter                             -> encoder mot måling mot x̂         (hel bredde)

Figurstørrelsene er laget for en A4-rapport med tekstbredde ca. 16 cm:
  "hel"  : \\includegraphics[width=\\textwidth]{...}
  "halv" : to ved siden av hverandre, \\begin{subfigure}{0.49\\textwidth} ... \\includegraphics[width=\\linewidth]{...}
Figuren lages i riktig størrelse, så skrifta blir like stor som oppgitt i FORMATER.
"""
import os
import sys
import glob
import numpy as np
import scipy.io as sio
import matplotlib
matplotlib.use("Agg")  # lagrer bare til fil, åpner ikke vinduer
import matplotlib.pyplot as plt

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(REPO, "HelikopterParakopter")
TS = 0.002          # tidssteg i Simulink [s]
T_START = 0.05      # hopp over de første samplene [s] (sensorene hopper helt i starten)
CM = 1 / 2.54


# ----------------------------------------------------------------------------------------------
# Lasting
# ----------------------------------------------------------------------------------------------
def load_mat(path, Ts=TS):
    """Laster en .mat-fil og returnerer (t, values) med én kolonne per signal.

    Håndterer tre formater:
      1. Gammelt:  simout er en ren matrise (N x M)                 -> tid lages fra Ts
      2. Nytt:     simout er "Structure With Time"                  -> simout.time, simout.signals.values
      3. To File:  matrise (M+1 x N) der første rad er tid          -> variabelnavn 'ans'
    """
    data = sio.loadmat(path)
    keys = [k for k in data if not k.startswith("__")]
    key = "simout" if "simout" in data else keys[0]
    var = data[key]
    if var.dtype.names is not None:
        s = var[0, 0]
        values = np.asarray(s["signals"][0, 0]["values"], dtype=float)
        t = np.asarray(s["time"], dtype=float).ravel()
        if t.size != values.shape[0]:
            t = np.arange(values.shape[0]) * Ts
        return t, values
    var = np.asarray(var, dtype=float)
    if var.shape[0] < var.shape[1] and var[0, 0] == 0 and np.allclose(np.diff(var[0, :10]), Ts):
        return var[0, :], var[1:, :].T
    return np.arange(var.shape[0]) * Ts, var


# ----------------------------------------------------------------------------------------------
# Kolonner (samme rekkefølge som muxen til "To File"/"To Workspace" i Simulink-modellene)
#   6 signaler : Lab 1 og de første Lab 2-stegtestene (bare encoder)
#   8          : + joystick (= referansen r = [p_c, ė_c])
#  14          : + akselerometer og gyro (rå IMU)                              Lab 3, håndtester
#  19          : + vinkler fra akselerometeret og gyro transformert til ṗ, ė, λ̇  Lab 3
#  22          : + integrert gyro (∫ṗ, ∫ė, ∫λ̇)                                 Lab 4
#  28/31/34    : + Kalman-estimatet x̂ = [p ṗ e ė λ λ̇] (+ 3 eller 6 bias-tilstander)
# ----------------------------------------------------------------------------------------------
K = dict(travel=0, travel_rate=1, pitch=2, pitch_rate=3, elev=4, elev_rate=5,
         joy_x=6, joy_y=7,
         acc_x=8, acc_y=9, acc_z=10, gyro_p=11, gyro_e=12, gyro_l=13,
         p_acc=14, e_acc=15, pd_gyro=16, ed_gyro=17, ld_gyro=18,
         int_p=19, int_e=20, int_l=21,
         xh_p=22, xh_pd=23, xh_e=24, xh_ed=25, xh_l=26, xh_ld=27)
IMU_KOLONNER = range(8, 22)  # alt som kommer fra IMU-en (ikke encoder, joystick eller x̂)


# ----------------------------------------------------------------------------------------------
# Stil per kilde. Encoder ligger øverst (høyest z) så den ikke drukner i sensorstøyen.
# Ingen kilder deler hovedfarge. Flere signaler fra samme kilde i ett panel bruker neste farge i lista.
# ----------------------------------------------------------------------------------------------
STIL = {
    "Reference":       dict(colors=["#000000"], lw=1.2, alpha=0.9, z=5, ls="--"),
    "Encoder":         dict(colors=["#0b3c8c"], lw=1.5, alpha=0.7, z=4, ls="-"),            # mørkeblå
    "Kalman":          dict(colors=["#d62728"], lw=1.2, alpha=0.85, z=3, ls="-"),           # rød
    # Målingene er bredere enn x̂ og ligger under, så de synes som en kant selv når x̂ = måling.
    # Accelerometer: vinkler regnet fra akselerometeret (lign. 2.19). I håndtestene: rå x/y/z.
    "Accelerometer":   dict(colors=["#2ca02c", "#8c564b", "#e377c2"], lw=1.6, alpha=0.7, z=2, ls="-"),  # grønn, brun, rosa
    # Gyro: gyromålingen transformert til Euler-rater (ṗ, ė, λ̇). I håndtestene: rå gyro per akse.
    "Gyro":            dict(colors=["#ff7f0e", "#17becf", "#bcbd22"], lw=1.6, alpha=0.7, z=2, ls="-"),  # oransje, cyan, oliven
    # Gyro (raw): rå gyro før transformasjonen, bare der den sammenlignes med den transformerte (2.3.2)
    "Gyro (raw)":      dict(colors=["#17becf"], lw=2.2, alpha=0.6, z=1, ls="-"),            # cyan
    "Integrated gyro": dict(colors=["#9467bd"], lw=2.4, alpha=0.5, z=1.5, ls="-"),          # lilla
}

# Fast rekkefølge i den felles legenden: fasit, målinger, estimat, referanse.
# "Gyro (raw)" må stå før "Gyro" fordi labelen sammenlignes med startswith.
LEGEND_REKKEFOLGE = ["Encoder", "Accelerometer", "Gyro (raw)", "Gyro", "Integrated gyro", "Kalman", "Reference"]

# Størrelser. bredde = bredden figuren får i rapporten.
FORMATER = {
    "halv":     dict(bredde=7.8, panelhoyde=3.4, font=9,  legend_kol=2),  # to ved siden av hverandre
    "hel":      dict(bredde=16.0, panelhoyde=3.8, font=10, legend_kol=4),  # full tekstbredde, én kolonne
    "rutenett": dict(bredde=16.0, panelhoyde=3.6, font=10, legend_kol=5),  # full tekstbredde, to kolonner
}


# ----------------------------------------------------------------------------------------------
# Små byggeklosser
# ----------------------------------------------------------------------------------------------
def sig(kilde, kol, navn=""):
    """Ett signal: kilde (bestemmer farge), kolonne (int eller array), og navn som brukes i legenden
    hvis flere signaler fra samme kilde ligger i samme panel."""
    return (kilde, kol, navn)


def panel(tittel, signaler, sentrer_null=False):
    return dict(tittel=tittel, signaler=signaler, sentrer_null=sentrer_null)


def referanse(V, kol):
    """Joystick-referansen tas bare med hvis den faktisk er brukt (ikke bare nuller)."""
    if V.shape[1] > kol and np.any(np.abs(V[:, kol]) > 1e-6):
        return [sig("Reference", kol)]
    return []


def har_xhat(V):
    return V.shape[1] >= 28


def vinkelmaaling(V):
    """Hvilken vinkelmåling ble sendt til Kalmanfilteret?
    De første Lab 4-forsøkene brukte integrert gyro, "AI_Help"-forsøkene akselerometervinkler.
    Filteret følger målingen tett, så vi velger den som ligger nærmest x̂_p."""
    ok = np.isfinite(V[:, K["p_acc"]]) & np.isfinite(V[:, K["int_p"]])
    feil_acc = np.nanmean((V[ok, K["xh_p"]] - V[ok, K["p_acc"]]) ** 2)
    feil_int = np.nanmean((V[ok, K["xh_p"]] - V[ok, K["int_p"]]) ** 2)
    return "Accelerometer" if feil_acc < feil_int else "Integrated gyro"


# ----------------------------------------------------------------------------------------------
# Oppsett per lab: returnerer (format, paneler, antall kolonner)
# ----------------------------------------------------------------------------------------------
def oppsett_lab1(navn, t, V):
    # PD-regulering av pitch. Referansen p_c er ikke logget i Lab 1, så vi viser responsen.
    return "halv", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"])]),
        panel("Pitch rate [rad/s]", [sig("Encoder", K["pitch_rate"])], sentrer_null=True),
    ], 1


def oppsett_lab2_steg(navn, t, V):
    # Stegtester: x (p_c) eller y (ė_c) går fra 0 til 0.5 ved t = 5 s (se Lab2_notater.md).
    # De første filene har bare encoder-signalene, så steget lages ut fra filnavnet.
    if V.shape[1] >= 8:
        ref_p, ref_ed = referanse(V, K["joy_x"]), referanse(V, K["joy_y"])
    else:
        steg = 0.5 * (t >= 5.0)
        ref_p = [sig("Reference", steg)] if "-x_" in navn else []
        ref_ed = [sig("Reference", steg)] if "-y_" in navn else []
    return "halv", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"])] + ref_p),
        panel("Elevation rate [rad/s]", [sig("Encoder", K["elev_rate"])] + ref_ed, sentrer_null=True),
        panel("Travel rate [rad/s]", [sig("Encoder", K["travel_rate"])], sentrer_null=True),
    ], 1


def oppsett_lab2_joystick(navn, t, V):
    # Fri flyging med joystick: sporing av r = [p_c, ė_c], og hva det gjør med elevation og travel.
    return "rutenett", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"])] + referanse(V, K["joy_x"])),
        panel("Elevation rate [rad/s]", [sig("Encoder", K["elev_rate"])] + referanse(V, K["joy_y"]), sentrer_null=True),
        panel("Elevation [rad]", [sig("Encoder", K["elev"])]),
        panel("Travel rate [rad/s]", [sig("Encoder", K["travel_rate"])], sentrer_null=True),
    ], 2


def oppsett_lab3_handtest(navn, t, V):
    # Helikopteret beveges for hånd i én akse. Viser encoder-vinkelen, alle tre gyro-aksene
    # mot encoder-raten (hvilken akse svarer?) og akselerometeret (grunnlaget for lign. 2.19).
    akse = "Elevation" if "Vertical" in navn else "Travel" if "Horizontal" in navn else "Pitch"
    vinkel, rate = {"Elevation": ("elev", "elev_rate"), "Travel": ("travel", "travel_rate"),
                    "Pitch": ("pitch", "pitch_rate")}[akse]
    return "halv", [
        panel(f"{akse} [rad]", [sig("Encoder", K[vinkel])]),
        panel(f"{akse} rate [rad/s]", [sig("Encoder", K[rate]),
                                       sig("Gyro", K["gyro_p"], "p"),
                                       sig("Gyro", K["gyro_e"], "e"),
                                       sig("Gyro", K["gyro_l"], "λ")], sentrer_null=True),
        panel("Accelerometer [m/s²]", [sig("Accelerometer", K["acc_x"], "x"),
                                       sig("Accelerometer", K["acc_y"], "y"),
                                       sig("Accelerometer", K["acc_z"], "z")]),
    ], 1


def oppsett_lab3_gyro(navn, t, V):
    # 2.3.2/2.3.3: rå gyro mot gyro transformert til ṗ, ė, λ̇, og akselerometervinkler, mot encoder.
    return "rutenett", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"]), sig("Accelerometer", K["p_acc"])]),
        panel("Pitch rate [rad/s]", [sig("Encoder", K["pitch_rate"]), sig("Gyro (raw)", K["gyro_p"]),
                                     sig("Gyro", K["pd_gyro"])], sentrer_null=True),
        panel("Elevation [rad]", [sig("Encoder", K["elev"]), sig("Accelerometer", K["e_acc"])]),
        panel("Elevation rate [rad/s]", [sig("Encoder", K["elev_rate"]), sig("Gyro (raw)", K["gyro_e"]),
                                         sig("Gyro", K["ed_gyro"])], sentrer_null=True),
        panel("Travel [rad]", [sig("Encoder", K["travel"])]),
        panel("Travel rate [rad/s]", [sig("Encoder", K["travel_rate"]), sig("Gyro (raw)", K["gyro_l"]),
                                      sig("Gyro", K["ld_gyro"])], sentrer_null=True),
    ], 2


def oppsett_lab3_flyging(navn, t, V):
    # LQR med Luenberger-observer: akselerometer- og gyromålingene mot encoder, og sporing av referansen.
    return "rutenett", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"]), sig("Accelerometer", K["p_acc"])] + referanse(V, K["joy_x"])),
        panel("Pitch rate [rad/s]", [sig("Encoder", K["pitch_rate"]), sig("Gyro", K["pd_gyro"])], sentrer_null=True),
        panel("Elevation [rad]", [sig("Encoder", K["elev"]), sig("Accelerometer", K["e_acc"])]),
        panel("Elevation rate [rad/s]", [sig("Encoder", K["elev_rate"]), sig("Gyro", K["ed_gyro"])]
              + referanse(V, K["joy_y"]), sentrer_null=True),
        panel("Travel [rad]", [sig("Encoder", K["travel"])]),
        panel("Travel rate [rad/s]", [sig("Encoder", K["travel_rate"]), sig("Gyro", K["ld_gyro"])], sentrer_null=True),
    ], 2


def oppsett_lab4_imu(navn, t, V):
    # 2.4.1 uten Kalman: målingene som R_d estimeres fra (akselerometer-vinkler og integrert gyro) mot encoder.
    return "rutenett", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"]), sig("Accelerometer", K["p_acc"]),
                              sig("Integrated gyro", K["int_p"])] + referanse(V, K["joy_x"])),
        panel("Pitch rate [rad/s]", [sig("Encoder", K["pitch_rate"]), sig("Gyro", K["pd_gyro"])], sentrer_null=True),
        panel("Elevation [rad]", [sig("Encoder", K["elev"]), sig("Accelerometer", K["e_acc"]),
                                  sig("Integrated gyro", K["int_e"])]),
        panel("Elevation rate [rad/s]", [sig("Encoder", K["elev_rate"]), sig("Gyro", K["ed_gyro"])]
              + referanse(V, K["joy_y"]), sentrer_null=True),
        panel("Travel [rad]", [sig("Encoder", K["travel"]), sig("Integrated gyro", K["int_l"])]),
        panel("Travel rate [rad/s]", [sig("Encoder", K["travel_rate"]), sig("Gyro", K["ld_gyro"])], sentrer_null=True),
    ], 2


def oppsett_lab4_kalman(navn, t, V):
    # Kalmanfilter: encoder (fasit) mot målingen filteret fikk, mot estimatet x̂.
    m = vinkelmaaling(V)
    p_maal = K["p_acc"] if m == "Accelerometer" else K["int_p"]
    e_maal = K["e_acc"] if m == "Accelerometer" else K["int_e"]
    return "rutenett", [
        panel("Pitch [rad]", [sig("Encoder", K["pitch"]), sig(m, p_maal), sig("Kalman", K["xh_p"])]
              + referanse(V, K["joy_x"])),
        panel("Pitch rate [rad/s]", [sig("Encoder", K["pitch_rate"]), sig("Gyro", K["pd_gyro"]),
                                     sig("Kalman", K["xh_pd"])], sentrer_null=True),
        panel("Elevation [rad]", [sig("Encoder", K["elev"]), sig(m, e_maal), sig("Kalman", K["xh_e"])]),
        panel("Elevation rate [rad/s]", [sig("Encoder", K["elev_rate"]), sig("Gyro", K["ed_gyro"]),
                                         sig("Kalman", K["xh_ed"])] + referanse(V, K["joy_y"]), sentrer_null=True),
        panel("Travel [rad]", [sig("Encoder", K["travel"]), sig("Integrated gyro", K["int_l"]),
                               sig("Kalman", K["xh_l"])]),
        panel("Travel rate [rad/s]", [sig("Encoder", K["travel_rate"]), sig("Gyro", K["ld_gyro"]),
                                      sig("Kalman", K["xh_ld"])], sentrer_null=True),
    ], 2


def velg_oppsett(path, t, V):
    navn = os.path.basename(path)
    mappe = os.path.basename(os.path.dirname(path))
    n = V.shape[1]
    varighet = t[-1] - t[0]
    if mappe == "Lab1":
        return oppsett_lab1(navn, t, V)
    if mappe in ("Lab2", "Lab_2_1", "Lab_2_2"):
        if n == 6 or varighet <= 12:
            return oppsett_lab2_steg(navn, t, V)
        return oppsett_lab2_joystick(navn, t, V)
    if mappe == "Lab3":
        if n == 14:
            return oppsett_lab3_handtest(navn, t, V)
        if navn.startswith("2_3_2"):
            return oppsett_lab3_gyro(navn, t, V)
        return oppsett_lab3_flyging(navn, t, V)
    if mappe == "Lab4":
        return oppsett_lab4_kalman(navn, t, V) if har_xhat(V) else oppsett_lab4_imu(navn, t, V)
    raise ValueError(f"Ukjent mappe: {mappe}")


# ----------------------------------------------------------------------------------------------
# Tegning
# ----------------------------------------------------------------------------------------------
def y_grenser(linjer, sentrer_null):
    """Encoder og referanse vises alltid helt. Støyete sensor-/estimatsignaler skaleres etter
    0.1–99.9-persentilen, så enkeltstående glitcher ikke presser resten flatt."""
    lo, hi = [], []
    for kilde, y in linjer:
        y = y[np.isfinite(y)]
        if y.size == 0:
            continue
        if kilde in ("Encoder", "Reference"):
            lo.append(y.min()); hi.append(y.max())
        else:
            lo.append(np.percentile(y, 0.1)); hi.append(np.percentile(y, 99.9))
    if not lo:
        return None
    lo, hi = min(lo), max(hi)
    luft = 0.08 * (hi - lo) if hi > lo else 0.1 * max(abs(hi), 0.1)
    lo, hi = lo - luft, hi + luft
    if sentrer_null:
        m = max(abs(lo), abs(hi))
        lo, hi = -m, m
    return lo, hi


def rad_for_rad(items, ncol):
    """matplotlib fyller legenden kolonne for kolonne. Stokk om så den leses rad for rad."""
    nrad = int(np.ceil(len(items) / ncol))
    return [items[r * ncol + c] for c in range(ncol) for r in range(nrad) if r * ncol + c < len(items)]


def tegn(path, t, V, fmt, paneler, ncols, ugyldig_encoder):
    f = FORMATER[fmt]
    nrows = int(np.ceil(len(paneler) / ncols))
    for p in paneler:
        p["signaler"] = [s for s in p["signaler"] if not (s[0] == "Encoder" and ugyldig_encoder)]
    # rutenett: én felles legend øverst. Én kolonne: legend under hvert panel (bare hvis det er >1 linje),
    # og ekstra høyde per legend-rad så panelene ikke klemmes.
    kilder = {s[0] for p in paneler for s in p["signaler"]}
    felles_legend = ncols > 1 and len(kilder) > 1  # én kilde: tittelen sier nok, ingen legend
    # Gjennomsiktighet bare i figurer der målinger/estimater faktisk overlapper (referansen er tynn og stiplet)
    overlapp = any(len({s[0] for s in p["signaler"]} - {"Reference"}) > 1 for p in paneler)
    if ncols > 1:
        ekstra = 1.2 if felles_legend else 0.0
    else:
        ekstra = sum(0.5 * np.ceil(len(p["signaler"]) / f["legend_kol"]) + 0.3
                     for p in paneler if len(p["signaler"]) > 1)
    hoyde = nrows * f["panelhoyde"] + ekstra + 0.8
    rc = {"font.size": f["font"], "axes.titlesize": f["font"], "axes.labelsize": f["font"],
          "xtick.labelsize": f["font"], "ytick.labelsize": f["font"], "legend.fontsize": f["font"]}
    with plt.rc_context(rc):
        fig, axes = plt.subplots(nrows, ncols, figsize=(f["bredde"] * CM, hoyde * CM), sharex=True,
                                 squeeze=False, layout="constrained")
        felles = {}  # legend-label -> handle (rutenett)
        for i, ax in enumerate(axes.flat):
            if i >= len(paneler):
                ax.set_visible(False)
                continue
            p = paneler[i]
            signaler = p["signaler"]
            antall = {}
            for s in signaler:
                antall[s[0]] = antall.get(s[0], 0) + 1
            en_kilde = len(antall) == 1  # f.eks. bare akselerometer: tittelen sier kilden, legenden bare x/y/z
            brukt, linjer = {}, []
            for pos, (kilde, kol, navn) in enumerate(signaler):
                y = kol if isinstance(kol, np.ndarray) else V[:, kol]
                st = STIL[kilde]
                k = brukt.get(kilde, 0); brukt[kilde] = k + 1
                if antall[kilde] == 1 or not navn:
                    label = kilde
                else:
                    label = navn if en_kilde else f"{kilde} {navn}"
                alpha = st["alpha"] if overlapp else 1.0
                (h,) = ax.plot(t, y, color=st["colors"][k % len(st["colors"])], lw=st["lw"], alpha=alpha,
                               ls=st["ls"], zorder=st["z"] + 0.01 * pos, label=label)
                linjer.append((kilde, y))
                felles.setdefault(label, h)
            g = y_grenser(linjer, p["sentrer_null"])
            if g:
                ax.set_ylim(*g)
            ax.set_title(p["tittel"], loc="left")
            ax.grid(True, alpha=0.3)
            ax.set_xlim(t[0] - T_START - 0.05, t[-1] + 0.05)  # samme luft som før: fra -0.05 s
            if ncols == 1:
                ax.tick_params(labelbottom=True)  # tidstall på alle panelene
                if len(signaler) > 1:
                    ncol = len(signaler) if en_kilde and len(signaler) <= 3 else min(len(signaler), f["legend_kol"])
                    h, l = ax.get_legend_handles_labels()
                    leg = ax.legend(rad_for_rad(h, ncol), rad_for_rad(l, ncol), loc="upper center",
                                    bbox_to_anchor=(0.5, -0.16), ncol=ncol,
                                    frameon=False, handlelength=1.4, handletextpad=0.4, columnspacing=1.0)
                    for line in leg.get_lines():
                        line.set_linewidth(2.2); line.set_alpha(1)
        if felles_legend:
            labels = sorted(felles, key=lambda l: next((i for i, k in enumerate(LEGEND_REKKEFOLGE)
                                                         if l.startswith(k)), 99))
            leg = fig.legend([felles[l] for l in labels], labels, loc="outside upper center",
                             ncol=min(len(labels), f["legend_kol"]), frameon=False,
                             handlelength=1.6, handletextpad=0.4, columnspacing=1.2)
            for line in leg.get_lines():
                line.set_linewidth(2.2); line.set_alpha(1)
        fig.supxlabel("Time [s]", fontsize=f["font"])
        pdf = os.path.splitext(path)[0] + ".pdf"
        fig.savefig(pdf)
        plt.close(fig)
    return pdf


def plott_fil(path):
    t, V = load_mat(path)
    if V.shape[0] < 50:
        return None, f"hoppet over: bare {V.shape[0]} sample(r) i filen"
    # Hopp over starten av målingen
    keep = (t - t[0]) >= T_START
    t, V = t[keep], V[keep].copy()
    # IMU-en leverer ikke data de første ~0.35 s (alle akselerometerverdier er 0). Akselerometervinklene blir da
    # atan(0/0) = π/2. Disse samplene er ikke målinger, så de fjernes fra IMU-signalene.
    if V.shape[1] >= 14:
        tom = (V[:, K["acc_x"]] == 0) & (V[:, K["acc_y"]] == 0) & (V[:, K["acc_z"]] == 0)
        V[np.ix_(tom, [c for c in IMU_KOLONNER if c < V.shape[1]])] = np.nan
    # Encoder-data som er åpenbart ødelagt (pitch/elevation langt utenfor ±2π) tas ikke med.
    ugyldig = np.nanmax(np.abs(V[:, [K["pitch"], K["elev"]]])) > 2 * np.pi
    fmt, paneler, ncols = velg_oppsett(path, t, V)
    pdf = tegn(path, t, V, fmt, paneler, ncols, ugyldig)
    merknad = f"{fmt}, {len(paneler)} paneler"
    if ugyldig:
        merknad += ", ENCODER UGYLDIG (utelatt)"
    return pdf, merknad


# ----------------------------------------------------------------------------------------------
# Lab 1: polplasseringene oppå hverandre, og det ustabile forsøket i en egen figur
# ----------------------------------------------------------------------------------------------
# (fil, polene i legenden, farge). Fargene er Okabe-Ito: skiller seg godt, også for fargeblinde.
# Legenden har tre kolonner: første rad er de reelle stabile polene, andre rad de komplekse.
LAB1_SAMMENLIGNING = [
    ("verdier_lab_1_v05.mat",     r"$\lambda_{1,2} = -0.5$",            "#0072B2"),  # blå
    ("verdier_lab_1_v1.mat",      r"$\lambda_{1,2} = -1$",              "#E69F00"),  # oransje
    ("verdier_lab_1_v2.mat",      r"$\lambda_{1,2} = -2$",              "#009E73"),  # grønn
    ("lab1_complex_conjugat.mat", r"$\lambda_{1,2} = -3 \pm 2i$",       "#CC79A7"),  # rosa
    ("lab1_ren_imaginær.mat",     r"$\lambda_{1,2} = \pm 2i$",          "#000000"),  # svart
]
# Det ustabile forsøket går til ±1.8 rad og ±6 rad/s og ville gjort de andre flate, så det får egen figur.
LAB1_USTABIL = [
    ("lab1 _1_-2.mat",            r"$\lambda_1 = 1,\ \lambda_2 = -2$",  "#D55E00"),  # rødoransje
]
LAB1_LENGDE = 10.0  # [s] alle forsøkene kuttes til samme lengde (alle letter ved t ≈ 0.5 s)


def lab1_figur(forsok, ut):
    """Pitch og pitch rate for flere forsøk oppå hverandre, 0 til LAB1_LENGDE sekunder.
    Begge Lab 1-figurene får samme størrelse og tidsakse, så de kan sammenlignes i rapporten."""
    mappe = os.path.join(DATA, "Lab1")
    f = FORMATER["hel"]
    paneler = [("Pitch [rad]", K["pitch"]), ("Pitch rate [rad/s]", K["pitch_rate"])]
    rc = {"font.size": f["font"], "axes.titlesize": f["font"], "axes.labelsize": f["font"],
          "xtick.labelsize": f["font"], "ytick.labelsize": f["font"], "legend.fontsize": f["font"]}
    with plt.rc_context(rc):
        fig, axes = plt.subplots(len(paneler), 1, figsize=(f["bredde"] * CM, (len(paneler) * 4.4 + 2.0) * CM),
                                 sharex=True, layout="constrained")
        for n, (fil, navn, farge) in enumerate(forsok):
            t, V = load_mat(os.path.join(mappe, fil))
            t = t - t[0]
            keep = (t >= T_START) & (t <= LAB1_LENGDE)
            if t[-1] < LAB1_LENGDE - 0.1:
                print(f"     merk: {fil} er bare {t[-1]:.1f} s lang")
            for ax, (tittel, kol) in zip(axes, paneler):
                ax.plot(t[keep], V[keep, kol], color=farge, lw=1.3, alpha=0.9, zorder=10 - n, label=navn)
        for ax, (tittel, kol) in zip(axes, paneler):
            ax.set_title(tittel, loc="left")
            ax.grid(True, alpha=0.3)
            ax.set_xlim(0, LAB1_LENGDE)
        h, l = axes[0].get_legend_handles_labels()
        ncol = min(3, len(h))
        leg = fig.legend(rad_for_rad(h, ncol), rad_for_rad(l, ncol), loc="outside upper center", ncol=ncol,
                         frameon=False, handlelength=1.8, handletextpad=0.5, columnspacing=1.6)
        for line in leg.get_lines():
            line.set_linewidth(2.5); line.set_alpha(1)
        fig.supxlabel("Time [s]", fontsize=f["font"])
        pdf = os.path.join(mappe, ut)
        fig.savefig(pdf)
        plt.close(fig)
    return pdf


def finn_filer(filtre):
    filer = []
    for p in sorted(glob.glob(os.path.join(DATA, "**", "*.mat"), recursive=True)):
        rel = os.path.relpath(p, REPO)
        if "_quarc_win64" in rel or "slprj" in rel:  # byggefiler fra QUARC, ikke måledata
            continue
        if filtre and not any(f in rel for f in filtre):
            continue
        filer.append(p)
    return filer


if __name__ == "__main__":
    filer = finn_filer(sys.argv[1:])
    for p in filer:
        rel = os.path.relpath(p, REPO)
        try:
            pdf, merknad = plott_fil(p)
            print(f"{'OK  ' if pdf else '--  '} {rel}: {merknad}")
        except Exception as e:  # én dårlig fil skal ikke stoppe resten
            print(f"FEIL {rel}: {e}")
    if not sys.argv[1:] or any("Lab1" in a or "lab1" in a for a in sys.argv[1:]):
        for forsok, ut in [(LAB1_SAMMENLIGNING, "lab1_sammenligning.pdf"), (LAB1_USTABIL, "lab1_ustabil.pdf")]:
            pdf = lab1_figur(forsok, ut)
            print(f"OK   {os.path.relpath(pdf, REPO)}: {len(forsok)} Lab 1-forsøk i samme figur")
