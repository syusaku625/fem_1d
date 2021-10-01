import matplotlib.pyplot as plt

output_data_1_0 = open("output_1.0.dat")
out_1_0 = []
for value in output_data_1_0:
    out_1_0.append(float(value))

output_data_0_8 = open("output_0.8.dat")
out_0_8 = []
for value in output_data_0_8:
    out_0_8.append(float(value))

output_data_0_6 = open("output_0.6.dat")
out_0_6 = []
for value in output_data_0_6:
    out_0_6.append(float(value))

output_data_0_4 = open("output_0.4.dat")
out_0_4 = []
for value in output_data_0_4:
    out_0_4.append(float(value))

output_data_0_2 = open("output_0.2.dat")
out_0_2 = []
for value in output_data_0_2:
    out_0_2.append(float(value))

x = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0] 

fig, ax = plt.subplots()

ax.set_xlabel("x_location (mm)")

plt.plot(x, out_0_2, marker='o', color='b', lw=3, markersize=6, label="λ=0.2")
plt.plot(x, out_0_4, marker='o', color='g', lw=3, markersize=6, label="λ=0.4")
plt.plot(x, out_0_6, marker='o', color='r', lw=3, markersize=6, label="λ=0.6")
plt.plot(x, out_0_8, marker='o', color='c', lw=3, markersize=6, label="λ=0.8")
plt.plot(x, out_1_0, marker='o', color='m', lw=3, markersize=6, label="λ=1.0")

plt.legend()

plt.savefig('result.png')

