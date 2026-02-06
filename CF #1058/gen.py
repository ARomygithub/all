from random import randint

n, m = 500, 500
a = [[randint(0,1) for j in range(m)] for _ in range(n)]

print(1)
print(n, m)
for i in range(n):
    for j in range(m):
        print(a[i][j], end="")
    print()
