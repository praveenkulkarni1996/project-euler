fn = [13] * 16
f0 = [0] * 16
f1 = [1] * 16
fa = [1] * 16
f01 = [0] * 16
f0a = [0] * 16
f1a = [0] * 16
f01a = [0] * 16
for i in xrange(1, 16):
    fn[i] = fn[i - 1] *13
    f0[i] = fn[i - 1] + 14 * f0[i - 1]
    f1[i] = fn[i - 1] + 14 * f1[i - 1]
    fa[i] = fn[i - 1] + 14 * fa[i - 1]
    f01[i] = 15 * f01[i - 1] + f0[i - 1] + f1[i -1]
    f0a[i] = 15 * f0a[i - 1] + f0[i - 1] + fa[i -1]
    f1a[i] = 15 * f1a[i - 1] + f1[i - 1] + fa[i -1]
    f01a[i] = 16 * f01a[i - 1] + f01[i - 1] + f0a[i - 1] + f1a[i - 1]
print "answer =", str.upper(hex(sum(f01a)))[2:]
