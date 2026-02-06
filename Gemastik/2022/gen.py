import random
from random import randint
import sys

random.seed(int(sys.argv[1]))

tc = 1
n = randint(5,12)
# a = [randint(1,2000) for _ in range(n)]
a = []
for i in range(n):
    if(i==0):
        b = randint(1,12)
        a.append(b)
    else:
        b = 0
        if((i%2)==1):
            b = randint(a[i-1]+1,13)
        else:
            b = randint(1,a[i-1]-1)
        a.append(b)
    # print(a[i-1])
l = randint(0,n-2)
r = randint(l+1,n-1)
a = a[:l] + list(reversed(a[l:(r+1)])) + a[(r+1):]
# temp = a[idx]
# a[idx] = a[idx+1]
# a[idx+1] = temp
print(tc)
print(n)
print(' '.join([str(ai) for ai in a]))

# 301 2 swap
# 368 l,r
# 