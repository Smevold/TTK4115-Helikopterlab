import numpy as np
import scipy.io as sio # Scipy input output har funksjon for lesing av .mat-filer
import matplotlib.pyplot as plt

## Laster data 
# Trenger ikke .mat i filnavnet
data = sio.loadmat('HelikopterParakopter/Verdier_lab_1_v1') # Laster inn dataen fra stien

# data['simout'] = [0: travel, 1: travel_rate, 2: pitch, 3: pitch_rate, 4: elevation, 5: elevation_rate]


## Lager tidsarray
Ts = 0.002 # Timestep
sim_array_length = int(np.size(data['simout']) / np.size(data['simout'][0])) # Størrelsen på hele array delt på størrelsen på ett element
t = np.arange(sim_array_length) * Ts # Array med samme lengde som simout, med riktig timestep

fig, ax = plt.subplots()
ax.plot(t, data['simout'])
ax.legend("Travel", "Travel_rate", "Pitch", "Pitch_rate", "Elevation", "Elevation_rate")

fig.savefig("test.pdf")
plt.show()