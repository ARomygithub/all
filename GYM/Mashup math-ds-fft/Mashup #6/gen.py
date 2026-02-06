import sys
import random
from random import randint

random.seed(int(sys.argv[1]))
n = 20
t = ""
for _ in range(n):
    t += chr(randint(0,1) + ord('0'))
q = randint(5,15)
qry = []
for _ in range(q):
    l1 = randint(1,n)
    l2 = randint(1,n)
    ln = randint(1,n-max(l1,l2)+1)
    qry.append([l1,l2,ln])

print(n)
print(t)
print(q)
for i in range(q):
    print(qry[i][0], qry[i][1], qry[i][2])
    