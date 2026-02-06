import random
from random import randint
import sys

def main():
    argv = sys.argv
    random.seed(int(argv[1]))
    n = randint(1, 10**5)
    d = [randint(1, n) for _ in range(n)]
    print(n)
    print(' '.join(map(str, d)))

if __name__ == '__main__':
    main()