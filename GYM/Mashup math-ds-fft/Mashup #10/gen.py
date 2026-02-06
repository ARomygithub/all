import sys
import random
from random import randint

random.seed(int(sys.argv[1]))
t = 1
n = randint(1,20)
k = randint(0,n)
a = [randint(0,n) for i in range(n)]
print(t)
print(n, k)
print(" ".join([str(ai) for ai in a]))