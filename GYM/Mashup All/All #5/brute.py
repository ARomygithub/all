n, m, k = map(int, input().split())
# print(n, m) 
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ct = 0
inf = 10**20
for i in range(1,inf):
    ai = a[(i-1)%len(a)]
    bi = b[(i-1)%len(b)]
    if(ai!=bi):
        ct +=1
    if(ct==k):
        print(i)
        exit(0)