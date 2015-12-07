## Answer = 20492570929
f = [0, 1, 2];
g = [0, 1, 1, 2];
h = [0, 1, 1, 1, 2];

for i in range(1, 50):
    f.append(f[-1] + f[-2]);
    g.append(g[-1] + g[-3]);
    h.append(h[-1] + h[-4]);

print f[50] + g[50] + h[50] - 3;
