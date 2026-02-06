import sys
import random
from random import randint

random.seed(int(sys.argv[1]))
n = randint(1,10)
m = randint(1,10)
a = [randint(1,10) for i in range(n)]

print(n, m)
print(' '.join([str(ai) for ai in a]))