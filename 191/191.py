##  1918080160
a = [0, 1];
b = [0, 1];
c = [0, 0];
d = [0, 1];
e = [0, 0];
f = [0, 0];
g = [0, 0];
for i in range (1, 30):
    a.append(a[i] + b[i] + c[i]);
    b.append(a[i]);
    c.append(b[i])
    d.append(a[i] + b[i] + c[i]);
    e.append(d[i] + e[i] + f[i] + g[i])
    f.append(e[i] + d[i])
    g.append(f[i]);
n = 30
print a[n] + b[n] + c[n] + d[n] + e[n] + f[n] + g[n];
