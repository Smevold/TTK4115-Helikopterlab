import numpy as np
import scipy.io as sio  # Scipy input output har funksjon for lesing av .mat-filer
import matplotlib.pyplot as plt


def load_mat(path, Ts=0.002):
    """Laster en .mat-fil og returnerer (t, values).

    t      : (N,)   tidsvektor
    values : (N, M) én kolonne per signal

    Håndterer tre formater:
      1. Gammelt:  simout er en ren matrise (N x M)            -> tid lages fra Ts
      2. Nytt:     simout er "Structure With Time"
                   (simout.time, simout.signals.values)        -> f.eks. AccelGyroManTest_*.mat
      3. To File:  matrise (M+1 x N) der første rad er tid     -> f.eks. 2_3_3_*.mat (variabelnavn 'ans')
    """
    data = sio.loadmat(path)
    keys = [k for k in data if not k.startswith('__')]
    key = 'simout' if 'simout' in data else keys[0]
    var = data[key]

    # Format 2: Structure With Time
    if var.dtype.names is not None:
        s = var[0, 0]
        values = s['signals'][0, 0]['values']
        t = np.asarray(s['time']).ravel()
        if t.size != values.shape[0]:  # "Structure" uten tid -> lag tid selv
            t = np.arange(values.shape[0]) * Ts
        return t, values

    var = np.asarray(var, dtype=float)

    # Format 3: To File (første rad er tid, data ligger i rader)
    if var.shape[0] < var.shape[1] and np.allclose(np.diff(var[0, :10]), np.diff(var[0, :10])[0]) and var[0, 0] == 0:
        return var[0, :], var[1:, :].T

    # Format 1: gammel ren matrise
    t = np.arange(var.shape[0]) * Ts
    return t, var


## Laster data
path = 'HelikopterParakopter/Lab3/AccelGyroManTest_Horizontal.mat'
t, values = load_mat(path)
print(f"{path}: {values.shape[0]} samples, {values.shape[1]} signaler, t = {t[0]:.3f}..{t[-1]:.3f} s")

# Skriv inn signalene her (i samme rekkefølge som i Simulink-muxen): (kilde, navn).
# Kilden bestemmer fargen, og settes foran navnet i legenden.
signals = [
    ("Encoder",       "travel"),
    ("Encoder",       "travel rate"),
    ("Encoder",       "pitch"),
    ("Encoder",       "pitch rate"),
    ("Encoder",       "elevation"),
    ("Encoder",       "elevation rate"),
    ("Joystick",      "X"),
    ("Joystick",      "Y"),
    ("Accelerometer", "x-direction"),
    ("Accelerometer", "y-direction"),
    ("Accelerometer", "z-direction"),
    ("Gyroscope",     "p-direction"),
    ("Gyroscope",     "e-direction"),
    ("Gyroscope",     "lambda-direction"),
]
# Mangler det signaler i lista, får resten kilden "Ukjent".
signals += [("Ukjent", f"signal {i}") for i in range(len(signals), values.shape[1])]
labels = [f"{src} {name}" for src, name in signals]

## Farger per kilde: én tydelig hovedfarge per kilde.
# Hvis flere signaler fra samme kilde havner i samme subplot, brukes neste farge i lista.
source_colors = {
    "Encoder":       ["#1f77b4", "#17becf", "#9467bd"],  # blå, cyan, lilla
    "Gyroscope":     ["#d62728", "#ff7f0e", "#e377c2"],  # rød, oransje, rosa
    "Accelerometer": ["#2ca02c", "#bcbd22", "#8c564b"],  # grønn, olivengul, brun
    "Joystick":      ["#7f7f7f", "#000000"],             # grå, svart
    "Ukjent":        ["#9467bd", "#8c564b", "#e377c2"],
}

## Velg subplots her (1 til 4 stykker).
# Hvert subplot: (tittel, [kolonner som skal plottes]). Kolonnenumrene er indeksene i `signals` over.
# Kommenter inn/ut linjer for å velge hvor mange subplots du vil ha.
subplots = [
    ("Pitch rate [rad/s]",     [3, 11]),
    ("Elevation rate [rad/s]", [5, 12]),
    ("Travel rate [rad/s]",    [1, 13]),
    # ("Accelerometer [m/s²]",   [8, 9, 10]),
]

## Plotting
assert 1 <= len(subplots) <= 4, "Velg mellom 1 og 4 subplots"

fig, axes = plt.subplots(len(subplots), 1, figsize=(10, 2.6 * len(subplots) + 0.6),
                         sharex=True, squeeze=False)
axes = axes[:, 0]

for ax, (title, indices) in zip(axes, subplots):
    used = {}  # teller hvor mange signaler fra hver kilde som er brukt i dette subplottet
    for i in indices:
        src = signals[i][0]
        k = used.get(src, 0)
        used[src] = k + 1
        palette = source_colors[src]
        ax.plot(t, values[:, i],
                color=palette[k % len(palette)],
                linewidth=1.5,
                label=labels[i])
    ax.set_title(title, loc="left", fontsize=10)
    ax.grid(True, alpha=0.3)
    ax.legend(fontsize="small", loc="best")  # matplotlib finner plassen som dekker minst data

axes[-1].set_xlabel("Tid [s]")
# axes[-1].set_xlim(2, 5)  # zoom inn på et tidsintervall (gjelder alle subplots pga. sharex)
fig.tight_layout()

fig.savefig("test.pdf")
plt.show()
