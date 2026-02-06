print(2**17, 17)

for i in range(2**17):
    s = bin(i)
    s = s[2:]
    left = 17 - len(s)
    s = left*'0' + s
    print(s)