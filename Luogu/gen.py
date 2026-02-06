import sys
import random
from random import randint

n = (10**5)
m = 20
q = 3*(10**3)
a = [[randint(1,10**7) for i in range(n)] for j in range(m)]
qry = []
for i in range(q):
    qt = randint(1,2)
    if(qt==1):
        x = randint(1,m)
        y = x
        while(y==x):
            y = randint(1,m)
        qry.append([qt,x,y])
    else:
        x = randint(1,m)
        y = randint(1,n)
        qry.append([qt,x,y])

print(n, m, q)
print('\n'.join([' '.join([str(a[i][j]) for j in range(n)]) for i in range(m)]))
for i in range(q):
    print(qry[i][0], qry[i][1], qry[i][2])
