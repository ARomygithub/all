import sys
import random
from random import randint

random.seed(555)
W = randint(16,26)
w = []
v = []

input_length = 99

# N = len(w)
N = 24

w0 = w.copy()
v0 = v.copy()
for i in range(N):
    w0.append(randint(1,3))
    v0.append(randint(1,9))

best_v = 0
cost = 0
cost0 = -1
W0 = W

mx = 2*(10**7)

while(True):
    w = w0.copy()
    v = v0.copy()
    W = W0
    id = randint(-1,N-1)
    if(id<0):
        W = randint(16,26)
    else:
        w[id] = randint(1,3)
        v[id] = randint(1,9)

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
    if(cost>cost0):
        cost0 = cost
        w0 = w.copy()
        v0 = v.copy()
        W = W0
        print(cost0)
    else:
        rnd = randint(0,4)
        if(rnd==0):
            cost0 = cost
            w0 = w.copy()
            v0 = v.copy()
            W = W0   
    if(cost>mx):
        break         


print("Cost: " + str(cost))
print("Points earned: " + str(cost * 1e-3))
print(W)
for i in range(N):
    print(w[i], v[i])
