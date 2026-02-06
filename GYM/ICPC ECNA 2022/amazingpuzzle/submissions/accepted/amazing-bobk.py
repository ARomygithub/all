#!/usr/bin/python3

import queue

DIRS = "NESW"
DR = [1, 0, -1, 0]
DC = [0, 1, 0, -1]

#=========================
# choose one or the other
#-------------------------
# q = queue.Queue(6250000)
#-------------------------
QSIZE = 1000000
q = [0] * QSIZE
qh = -1
qt = 0
qc = 0
#=========================

(c, r, e) = map(int, input().split(' '))
(c1, r1, d1, c2, r2, d2) = input().split(' ')
c1 = int(c1) - 1
r1 = int(r1)
c2 = int(c2) - 1
r2 = int(r2)
e -= 1
r += 1
orient = (4 + DIRS.find(d2) - DIRS.find(d1)) % 4

hasWall = []
for i in range(r * c):
    hasWall.append([False, False, False, False])

walls = list(map(int, input().split(' ')))
for i in range(walls[0]):
    hasWall[walls[2 * i + 1] + c * walls[2 * i + 2] - 1][0] = True
    hasWall[walls[2 * i + 1] + c * (walls[2 * i + 2] + 1) - 1][2] = True

walls = list(map(int, input().split(' ')))
for i in range(walls[0]):
    hasWall[walls[2 * i + 1] + c * walls[2 * i + 2] - 1][1] = True
    hasWall[walls[2 * i + 1] + c * walls[2 * i + 2]][3] = True

# add exterior walls
for i in range(c):
    if i != e:
        hasWall[i+c][2] = True
    hasWall[i + c * (r - 1)][0] = True

for i in range(1, r):
    hasWall[c * i][3] = True
    hasWall[c * (i + 1) - 1][1] = True

dist = [-1] * (c * r * c * r)
bumps = [2147483647] * (c * r * c * r)

# starting configuration for BFS
curLoc = c1 + c * (r1 + r * (c2 + c * r2))
dist[curLoc] = 0
bumps[curLoc] = 0

# enqueue starting point
#=========================
# choose one or the other
#-------------------------
# q.put(curLoc)
#-------------------------
q[qt] = curLoc
qt = (qt + 1) % QSIZE
qc += 1
#=========================

# do the BFS (and turn your robot around, that's what it's all about)
#=========================
# choose one or the other
#-------------------------
# while not q.empty():
#     curLoc = q.get()
#-------------------------
while qc > 0:
    qh = (qh + 1) % QSIZE
    curLoc = q[qh]
    qc -= 1
#=========================

    # decode location
    tmp = curLoc
    c1 = tmp % c
    tmp = tmp // c
    r1 = tmp % r
    tmp = tmp // r
    c2 = tmp % c
    r2 = tmp // c

    # loop over all directions for robot A
    for d1 in range(4):
        # find orientation of robot B
        d2 = (d1 + orient) % 4

        # no bumps yet, since nobody has moved
        newBumps = 0

        # find new location of A
        c1new = c1
        r1new = r1

        # if A is on row 0, it has escaped and does not move
        if r1 > 0:
            # if there is a wall in the way, bump but no move
            if hasWall[c1 + c * r1][d1]:
                newBumps += 1
            else:
                c1new += DC[d1]
                r1new += DR[d1]

        # now do robot B
        c2new = c2
        r2new = r2

        if r2 > 0:
            if hasWall[c2 + c * r2][d2]:
                newBumps += 1
            else:
                c2new += DC[d2]
                r2new += DR[d2]

        # if A and B are on the same square, disregard this move
        # but, if both robots are at (e, 0) that's okay, since that's the goal
        if c1new != c2new or r1new != r2new or r1new == 0:
            # skip if positions are swapped
            if c1new == c2 and r1new == r2 and c2new == c1 and r2new == r1:
                continue
            # encode new location
            newLoc = c1new + c * (r1new + r * (c2new + c * r2new))
            newDist = dist[curLoc] + 1
            newBumps += bumps[curLoc]

            # if new location unseen, enqueue it for processing
            if dist[newLoc] == -1:
                dist[newLoc] = newDist
                bumps[newLoc] = newBumps
                #=========================
                # choose one or the other
                #-------------------------
                # q.put(newLoc)
                #-------------------------
                if qc == QSIZE:
                    print("Error!")
                q[qt] = newLoc
                qt = (qt + 1) % QSIZE
                qc += 1
                #=========================

            # if distance is the same but fewer bumps, remember bumps
            if dist[newLoc] == newDist and bumps[newLoc] > newBumps:
                bumps[newLoc] = newBumps

# BFS done, results at exit
print(dist[e + r * c * e], bumps[e + r * c * e])
