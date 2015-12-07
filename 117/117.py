#   Answer = 100808458960497
f = [0, 1, 2, 4, 8, 15];
for i in range(1, 50):
    f.append(f[-1] + f[-2] + f[-3] + f[-4]);
print f[50];

