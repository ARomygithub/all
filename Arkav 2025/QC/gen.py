import random
import sys
from random import randint

random.seed(int(sys.argv[1]))
n = 10
k = randint(1,7)
r = randint(1,n)


print(n,k,r)
