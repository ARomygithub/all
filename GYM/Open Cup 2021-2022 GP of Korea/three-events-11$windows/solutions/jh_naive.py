from sys import setrecursionlimit as SRL, stdin
SRL(150000)

def SCC(adj):
    # given |V| and adj, compute SCC
    def SC(i):
        nonlocal ind
        vin[i] = ind; vll[i] = ind; ind+= 1
        stack.append(i); stacked[i] = 1
        for j in adj[i]:
            if vin[j] == 0: SC(j); vll[i] = min(vll[i], vll[j])
            elif stacked[j]: vll[i] = min(vll[i], vin[j])
        if vll[i] == vin[i]:
            scc = []; j = 0
            while j != i:
                j = stack.pop(); stacked[j] = 0; scc.append(j)
            res.append(scc)
    v, ind, stack, res = len(adj), 1, [], []
    vin, vll, stacked = [0]*v, [0]*v, [0]*v
    for i in range(1, v):
        if vin[i] == 0: SC(i)
    return res

input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())

n = int(input())
rank = [None] + [tuple(MIS()) for i in range(n)]
adj = [[] for i in range(n+1)]
for i in range(1, n+1):
    for j in range(i+1, n+1):
        iwin = sum(rank[i][k] < rank[j][k] for k in range(3))
        if iwin >= 2: adj[i].append(j)
        else: adj[j].append(i)
scc = SCC(adj)
sidx = [0]*(n+1)
for i in range(len(scc)):
    for x in scc[i]: sidx[x] = i

for QUERY in range(int(input())):
    a, b = MIS()
    print("YES" if sidx[a] >= sidx[b] else "NO")
    