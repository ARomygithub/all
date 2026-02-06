import random
from random import randint
import sys

random.seed(int(sys.argv[1]))

tc = 10
mxv = 2**18 - 1
print(tc)
for _ in range(tc):
    # n = randint(10**4,10**5)
    n = 10**5
    a = [randint(0,mxv) for _ in range(n)]
    print(n)
    print(" ".join([str(ai) for ai in a]))
