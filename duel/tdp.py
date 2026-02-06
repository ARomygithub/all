def fct(x):
    ret = 1
    for i in range(1,x+1):
        ret *= i
    return ret

def C(a,b):
    return fct(a)/(fct(b)*fct(a-b))

bwh = C(50,15)
# print(bwh)
# print(C(12,0))
ats = 0
for i in range(0,3):
    ats += C(12,i)*C(38,15-i)
p1 = ats/bwh
p2 = 1-p1
print(p2)
