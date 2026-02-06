n = int(input())
a3 = 1
ans = 0

while(a3*3<=n):
    a3 *= 3
    ans += 1
if(a3==n):
    print(ans)
else:
    print(-1)