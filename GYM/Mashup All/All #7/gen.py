import sys
from random import randint
import random

random.seed(int(sys.argv[1]))
mxn = 140582
mxb = 187126
n = randint(2,mxn)
b = [randint(0,mxb) for i in range(n)]
print(n)
print(" ".join([str(bi) for bi in b]))
