import sys
import random
from random import randint

random.seed(int(sys.argv[1]))
# tc = randint(1,100)
tc = 1
print(tc)
for _ in range(tc):
    print(randint(1,7), randint(1,7))
