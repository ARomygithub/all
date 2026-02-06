def cek(s):
    st = set()
    for c in s:
        st.add(ord(c)-ord('0'))
    if(len(st)==1):
        return True
    if(len(st)==2):
        od = 0
        ev = 0
        for sti in st:
            if((sti%2)==1):
                od = 1
            else:
                ev = 1
        if(od>0 and ev>0):
            return True
    return False


n = int(input())

u = 2**n
ad = u
while(len(str(u))<=n):
    su = str(u)
    if(len(su)==n and cek(su)):
        print(su, u//ad)
    u += ad
