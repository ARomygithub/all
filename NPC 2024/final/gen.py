import sys
import random
from random import randint

random.seed(int(sys.argv[1]))
n = randint(1,10)
m = randint(1,100)
while(m>n*(n-1)//2):
    n = randint(1,100)
    m = randint(1,100)

k = randint(1,200)
maxcap = randint(1,50000)
suv = set()
while(len(suv)<m):
    u = randint(1,n-1)
    v = randint(u+1,n)
    suv.add((u,v))
uvc = []
for suvi in suv:
    u, v = suvi
    c = randint(1,20)
    uvc.append([u,v,c])
t = [randint(1,20) for i in range(n)]
print(n, m, k, maxcap)
for i in range(len(uvc)):
    print(uvc[i][0], uvc[i][1], uvc[i][2])
print(" ".join([str(ti) for ti in t]))
