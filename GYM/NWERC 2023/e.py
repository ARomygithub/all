
# print(input().split())
n, m = input().split()
n = int(n)
m = int(m)
# print(n, m)
pw2 = [0 for i in range(n)]
for i in range(m):
    qt, i, j = input().split()
    i = int(i)
    j = int(j)
    i -= 1
    j -= 1
    if(qt=="!"):
        pw2[i] += 2023**pw2[j]
    else:
        if(pw2[i]==pw2[j]):
            print("=")
        elif(pw2[i]<pw2[j]):
            print("<")
        else:
            print(">")
