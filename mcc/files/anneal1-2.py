import sys
import random
from random import randint

random.seed(555)
# W = randint(1,99)
W = 99
w = []
v = []

input_length = 99

# N = len(w)
N = 24

w0 = w.copy()
v0 = v.copy()
for i in range(N):
    w0.append(randint(1,9))
    v0.append(randint(1,9))

best_v = 0
cost = 0
cost0 = -1
W0 = W

mx = 8*(10**5)

while(True):
    w = w0.copy()
    v = v0.copy()
    W = W0
    id = randint(-1,N-1)
    if(id<0):
        W = randint(1,99)
    else:
        w[id] = randint(1,9)
        v[id] = randint(1,9)
    
    def should_swap(l, r):
        if v[l] * w[r] < v[r] * w[l]:
            return True
        if v[l] * w[r] == v[r] * w[l] and w[l] < w[r]:
            return True
        return False

    for i in range(1, N):
        while i > 0 and should_swap(i - 1, i):
            w[i], w[i - 1] = w[i - 1], w[i]
            v[i], v[i - 1] = v[i - 1], v[i]
            i -= 1

    best_v = 0
    cost = 0

    def heuristic(sw, sv, d):
        rw = min(W - sw, sum(w[i] for i in range(d, N)))
        rv = best_v + 1 - sv
        return v[d] * rw >= rv * w[d]

    def go(sw, sv, d):
        global cost, best_v
        cost += 1
        if d == N:
            if sv > best_v:
                best_v = sv
        elif sv > best_v or heuristic(sw, sv, d):
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
        if(rnd==0 and cost0//cost <=3):
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
