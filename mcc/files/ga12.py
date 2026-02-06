import sys
import random
from random import randint
from functools import cmp_to_key

random.seed(555)
N = 24

class Sol:
    def __init__(self):
        self.W = randint(16,26)
        self.w = []
        self.v = []
        for i in range(N):
            self.w.append(randint(1,9))
            self.v.append(randint(1,9))
    def go(self, sw, sv, d):
        self.cost += 1
        # print("1 ", cost)
        if sv + sum(self.v[i] for i in range(d, N)) > self.best_v:
            if d == N:
                self.best_v = sv
            else:
                if sw + self.w[d] <= self.W:
                    self.go(sw + self.w[d], sv + self.v[d], d + 1)
                self.go(sw, sv, d + 1)
    def calc(self):
        self.best_v = 0
        self.cost = 0
        self.go(0, 0, 0)
    

input_length = 99

# N = len(w)
def comp(sol1, sol2):
    return sol2.cost - sol1.cost

iter = 0
vsol = []
for _ in range(40):
    vsol.append(Sol())
    vsol[-1].calc()

vsol = sorted(vsol, key=cmp_to_key(comp))
mx = 2*(10**7)

while(iter<500):
    iter += 1
    # drop half-bottom
    for _ in range(20):
        vsol.pop()
    # mutation
    for i in range(20):
        soli = Sol()
        i1 = randint(0,19)
        i2 = randint(0,19)
        soli.W = vsol[i1].W
        potong = randint(0,N-2)
        for j in range(N):
            if(j<=potong):
                soli.w[j] = vsol[i1].w[j]
                soli.v[j] = vsol[i1].v[j]
            else:
                soli.w[j] = vsol[i2].w[j]
                soli.v[j] = vsol[i2].v[j]
        id = randint(-1,N-1)
        if(id<0):
            soli.W = randint(16,26)
        else:
            soli.w[id] = randint(1,9)
            soli.v[id] = randint(1,9)            
        # soli.calc()
        vsol.append(soli)
        vsol[-1].calc()
    # sort by cost
    vsol = sorted(vsol, key = cmp_to_key(comp))
    print(vsol[0].cost)
    if(vsol[0].cost > mx):
        break

print(input_length)
# print("Cost: " + str(cost))
# print("Points earned: " + str(cost * 1e-3))
for j in range(1):
    print(vsol[j].cost)
    print(vsol[j].W)
    for i in range(N):
        print(vsol[j].w[i], vsol[j].v[i])
    
