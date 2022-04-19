from matplotlib import pyplot as plt
import numpy as np

T_1 = np.array([12346.6,12243.7, 12063.6, 12273.7, 12252.0]);
T_2 = np.array([12302.0, 12302.0, 12336.2, 12273.7, 12267.0]);
T_4 = np.array([12437.9, 12437.9, 12515.6, 12468.0, 12528.3]);
T_8 = np.array([12387.0, 12403.0, 12371.4, 12473.5, 12359.1]);
T_12 = np.array([12449.5, 12449.5, 12449.5, 12378.3,12329.4]);
T_16 = np.array([12408.0, 12376.2, 12369.6, 12434.0, 12368.5]);
T_20 = np.array([12302.9, 12302.9, 12302.9, 12302.9, 12364.6]);
T_24 = np.array([12361.9, 12320.1, 12275.5, 12287.0, 12305.7]);
T_28 = np.array([12269.0, 12264.3, 12289.7, 12324.0, 12273.7]);
T_32 = np.array([12289.7, 12299.1, 12253.1, 12390.6, 12372.4]);

T = np.array([1,2,4,8,12,16,20,24,28,32]);


avg = np.array([np.average(T_1),np.average(T_2),np.average(T_4),np.average(T_8), np.average(T_12),np.average(T_16),np.average(T_20),np.average(T_24),np.average(T_28),np.average(T_32)]);

error = np.array([np.std(T_1),np.std(T_2),np.std(T_4),np.std(T_8), np.std(T_12),np.std(T_16),np.std(T_20),np.std(T_24),np.std(T_28),np.std(T_32)]);

plt.errorbar(T, avg, yerr=100*error, fmt='-');
plt.xlabel("Threads[N]");
plt.ylabel("Copy[MB/s]")
plt.show();
