import numpy as np
import matplotlib.pyplot as plt

s = 0.1
procs = range(1, 129)
speedup = map((lambda p : 1/(s+(1-s)/p)), procs)
efficiency = map((lambda p : 1/(s+(1-s)/p)/p), procs)

plt.figure(1)
plt.axis([0, 128, 0, 10])
plt.xlabel('Number of Processing elements')
plt.ylabel('Speedup')
plt.plot(procs, speedup, 'ro-', linewidth=2.0)

plt.figure(2)
plt.axis([0, 128, 0, 1])
plt.xlabel('Number of Processing elements')
plt.ylabel('Parallel Efficiency')
plt.plot(procs, efficiency, 'bo-', linewidth=2.0)
plt.show()
