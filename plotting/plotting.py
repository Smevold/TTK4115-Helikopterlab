import numpy as np
import scipy.io as sio # Scipy input output har funksjon for lesing av .mat-filer
import matplotlib.pyplot as plt

# Trenger ikke .mat i filnavnet
data = sio.loadmat('HelikopterParakopter/Verdier_lab_1_v1') # Laster inn dataen fra stien

# print("simout data:\n", data['simout']) # Det er kun Key: 'simout' som er relevant å se på

# data['simout'] ser slik ut: [0: travel, 1: travel_rate, 2: pitch, 3: pitch_rate, 4: elevation, 5: elevation_rate]

Ts = 0.002 # Timestep

## Lager tidsarray
sim_array_length = int(np.size(data['simout']) / np.size(data['simout'][0])) # Størrelsen på hele array delt på størrelsen på ett element
t = np.arange(0, sim_array_length, Ts) # Array med samme lengde som simout, med riktig timestep
