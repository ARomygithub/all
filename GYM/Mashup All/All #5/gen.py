import sys
import random
from random import randint

def main():
    random.seed(int(sys.argv[1]))    
    # print(randint(1,7))
    n = randint(1,5*10**4)
    m = randint(1,5*10**4)
    k = randint(1,10**6)
    a = [randint(1,10**4) for i in range(n)]
    b = [randint(1,10**4) for i in range(m)]
    a = list(set(a))
    b = list(set(b))
    n = len(a)
    m = len(b)
    random.shuffle(a)
    random.shuffle(b)
    print(n, m, k)
    for ai in a:
        print(ai, end=" ")
    print()
    for bi in b:
        print(bi, end=" ")
    exit(0)

if (__name__ == '__main__'):
    main()