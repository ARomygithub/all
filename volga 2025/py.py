t=int(input())
for _ in range(t):
    n = input()
    base = int(n)
    ans = []
    for c in range(1, 1 + len(n)):
        n = n[-1] + n[:-1]
        diff = int(n) - base
        if diff > 0 and diff % len(n) == c % len(n):
            ans += diff,
    
    print(len(ans))
    ans.sort()
    print(*ans)