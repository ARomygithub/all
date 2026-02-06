import sys
import random
from random import randint

random.seed(int(sys.argv[1]))

tc = 1
n = randint(7,10)
m = randint(20,25)
a = [randint(0,10) for i in range(n)]
s = set()
while(len(s)<(n-randint(2,4))):
    j = randint(0,n-1)
    s.add(j)
for si in s:
    a[si] = 0
topo = [i for i in range(1,n+1)]
random.shuffle(topo)
ed = []
for i in range(n-1):
    ed.append((topo[i], topo[randint(i+1,n-1)]))
while(len(ed)<m):
    i = randint(0,n-2)
    j = randint(i+1,n-1)
    ed.append((topo[i],topo[j]))

print(tc)
print(n, m)
print(" ".join([str(ai) for ai in a]))
for i in range(len(ed)):
    print(ed[i][0], ed[i][1])