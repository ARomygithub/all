import sys
import random
from random import randint
from functools import cmp_to_key

random.seed(555)
N = 24

best_v = 0
cost = 0

def getskor(W, w, v):
    best_v = 0
    cost = 0
    def go(sw, sv, d):
        global cost, best_v
        cost += 1
        if sv + sum(v[i] for i in range(d, N)) > best_v:
            if d == N:
                best_v = sv
            else:
                if sw + w[d] <= W:
                    go(sw + w[d], sv + v[d], d + 1)
                go(sw, sv, d + 1)

    go(0, 0, 0)
    return cost

class Sol:
    def __init__(self):
        self.W = randint(16,26)
        self.w = []
        self.v = []
        for i in range(N):
            self.w.append(randint(1,9))
            self.v.append(randint(1,9))
    def calc(self):
        self.cost = getskor(self.W, self.w, self.v)
        


input_length = 99

# N = len(w)
def comp(sol1, sol2):
    return sol2.cost - sol1.cost

iter = 0
vsol = []
for _ in range(100):
    vsol.append(Sol())
    vsol[-1].calc()

sorted(vsol, key=cmp_to_key(comp))
mx = 2*(10**7)
while(iter<1000):
    iter += 1
    # drop half-bottom
    for _ in range(50):
        vsol.pop()
    # mutation
    for i in range(50):
        soli = Sol()
        for j in range(N):
            soli.w[j] = vsol[i].w[j]
            soli.v[j] = vsol[i].v[j]
        soli.W = vsol[i].W
        id = randint(-1,N-1)
        if(id<0):
            soli.W = randint(16,26)
        else:
            soli.w[id] = randint(1,9)
            soli.v[id] = randint(1,9)
        soli.calc()
        vsol.append(soli)
    # sort by cost
    sorted(vsol, key = cmp_to_key(comp))
    if(vsol[0].cost > mx):
        break

print(input_length)
print("Cost: " + str(cost))
print("Points earned: " + str(cost * 1e-3))
print(vsol[0].W)
for i in range(N):
    print(vsol[0].w[i], vsol[0].v[i])
