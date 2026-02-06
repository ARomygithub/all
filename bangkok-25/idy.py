import io,os,sys
from collections import defaultdict
from itertools import accumulate
from bisect import bisect_left,bisect_right
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
get=lambda:list(map(int,input().split()))
from heapq import heapify,heappush,heappop,merge

t=int(input())
for _ in range(t):
    s = input().decode().strip()
    i = list()
    ic = list()
    icp = list()
    icpc = list()
    for idx,c in enumerate(s):
        if c == 'I':
            i.append([idx])
        if c == 'C':
            if i:
                ic.append(i.pop() + [idx]),
        if c == 'P':
            if ic:
                icp.append(ic.pop() + [idx]),

    icp.sort(key=lambda v:v[-1])
    free = [1] * (len(s))
    for v in icp:
        free[v[-1]] = 0

    ans = []
    for idx in reversed(range(len(s))):
        while icp and icp[-1][-1] > idx:
            free[icp.pop()[-1]] = 1
        if s[idx] != 'C': continue
        if free[idx] and icp:
            ans.append(icp.pop() + [idx])
    
    print(len(ans))
    for a in ans:
        for v in a: sys.stdout.write(f"{v + 1} ")
        sys.stdout.write("\n")