import sys
import random
from random import randint

random.seed(int(sys.argv[1]))
n = randint(8,8)
q = randint(20,40)
ats = 10
# v = [randint(1,ats) for _ in range(n)]
v = [8, 9, 10, 4, 3, 9, 8, 10]
qry = []
for _ in range(q):
    qt = randint(0,3)
    l = randint(1,n)
    r = randint(l,n)
    if(qt<=1):
        qry.append([qt,l,r,randint(-ats,ats)])
    else:
        qry.append([qt,l,r])
print(n,q)
print(' '.join([str(vi) for vi in v]))
for qi in qry:
    print(' '.join([str(qii) for qii in qi]))