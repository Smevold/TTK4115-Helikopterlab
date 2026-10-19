import os
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
path = 'HelikopterParakopter/Lab2/høy_q_5_lav_q_4.mat'
t, values = load_mat(path)

# Hopp over starten av målingen (sensorene hopper ofte helt i begynnelsen).
# Alt før t_start [s] fjernes. Sett t_start = 0 for å ta med alt.
t_start = 0.05
keep = t >= t_start
t, values = t[keep], values[keep]
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
    ("Euler", "pitch"),
    ("Euler", "elevation"),
    ("Euler",     "pitch rate"),
    ("Euler",     "elevation rate"),
    ("Euler",     "travel rate"),
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
    "Euler":         ["#9467bd", "#8c564b", "#e377c2"],
    "Ukjent":        ["#9467bd", "#8c564b", "#e377c2"],
}

## Velg subplots her (1 til MAX_SUBPLOTS stykker).
MAX_SUBPLOTS = 5
# Hvert subplot: (tittel, [kolonner som skal plottes]). Kolonnenumrene er indeksene i `signals` over.
# Kommenter inn/ut linjer for å velge hvor mange subplots du vil ha.
subplots = [
    ("Encoder [rad]",                 [0, 2, 4]),
    ("Encoder rate [rad/s]",          [1, 3, 5]),
    ("Joystick",                [6, 7]),
    # ("Pitch [rad]",           [2, 14]),
    # ("Pitch rate [rad/s]",     [3, 11, 16]),
    # ("Elevation [rad]",       [4, 15]),
    # ("Elevation rate [rad/s]", [5, 12, 17]),
    # ("Travel rate [rad/s]",    [1, 13, 18]),
    # ("Accelerometer [m/s²]",   [8, 9, 10]),
    # ("Everything",             list(range(len(signals)))),
]

## Tilpass til antall signaler i filen
# Filer med færre signaler (f.eks. 14 i stedet for 19) mangler de siste kolonnene.
# Signaler som ikke finnes i filen hoppes over, og subplots som blir tomme fjernes.
n_cols = values.shape[1]
filtered = []
for title, indices in subplots:
    present = [i for i in indices if i < n_cols]
    missing = [labels[i] if i < len(labels) else f"kolonne {i}" for i in indices if i >= n_cols]
    if missing:
        print(f"  '{title}': hopper over (finnes ikke i filen): {', '.join(missing)}")
    if present:
        filtered.append((title, present))
    else:
        print(f"  '{title}': ingen signaler igjen, subplottet fjernes")
subplots = filtered

## Plotting
assert 1 <= len(subplots) <= MAX_SUBPLOTS, f"Velg mellom 1 og {MAX_SUBPLOTS} subplots (har {len(subplots)})"

# Gjennomsiktighet på linjene: 1 = helt dekkende, 0 = usynlig
line_alpha = 0.7
# Rekkefølge: signalene tegnes i den rekkefølgen de står i `subplots`-lista,
# så det SISTE signalet havner ØVERST. Bytt rekkefølge der for å endre hva som ligger på toppen.
# Sett reverse_draw_order = True for å snu rekkefølgen i alle subplots (legenden beholder lista-rekkefølgen).
reverse_draw_order = False

# Grenser for tidsaksen [s] (gjelder alle subplots)
# None = automatisk: hele målingen vises, med 0.05 s luft på hver side.
# Vil du zoome inn, sett tall i stedet, f.eks. x_min, x_max = 2, 5
x_min, x_max = None, None
if x_min is None:
    x_min = -0.05
if x_max is None:
    x_max = t[-1] + 0.05

# Bare data innenfor [x_min, x_max] plottes, så y-aksen skaleres etter det som faktisk vises
visible = (t >= x_min) & (t <= x_max)
t_vis, values_vis = t[visible], values[visible]

fig, axes = plt.subplots(len(subplots), 1, figsize=(12, 2.6 * len(subplots) + 0.6),
                         sharex=True, squeeze=False, layout="constrained")
axes = axes[:, 0]

for ax, (title, indices) in zip(axes, subplots):
    used = {}  # teller hvor mange signaler fra hver kilde som er brukt i dette subplottet
    n = len(indices)
    for pos, i in enumerate(indices):
        src = signals[i][0]
        k = used.get(src, 0)
        used[src] = k + 1
        palette = source_colors[src]
        ax.plot(t_vis, values_vis[:, i],
                color=palette[k % len(palette)],
                linewidth=1.5,
                alpha=line_alpha,
                zorder=(n - pos) if reverse_draw_order else (pos + 1),
                label=labels[i])
    ax.set_title(title, loc="left", fontsize=10)
    ax.grid(True, alpha=0.3)
    # Legend utenfor plottet, til høyre
    leg = ax.legend(fontsize="small", loc="center left", bbox_to_anchor=(1.01, 0.5))
    for line in leg.get_lines():  # tykkere og helt dekkende linjer i legenden, så fargene er lette å se
        line.set_linewidth(2)
        line.set_alpha(1)

axes[-1].set_xlabel("Tid [s]")
axes[-1].set_xlim(x_min, x_max)  # gjelder alle subplots pga. sharex

## Lagre PDF i samme mappe som .mat-filen, med samme navn
# Sett en suffix hvis du lager flere plott fra samme .mat-fil, f.eks. "_rates" -> AccelGyroManTest_Horizontal_rates.pdf
suffix = ""
pdf_path = os.path.splitext(path)[0] + suffix + ".pdf"
fig.savefig(pdf_path)
print(f"Lagret: {pdf_path}")
plt.show()
