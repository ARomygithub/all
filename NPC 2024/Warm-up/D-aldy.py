from sys import stdin
input = stdin.readline

def fail(low:str, high) :
        print(f"Pacifista tidak nurut karena wewenang {low} lebih rendah dari {high}.")

def success(user, com) :
        print(f"Pacifista {com} sesuai dengan keinginan {user}.")

def same(user, com) :
        print(f"Pacifista sudah diperintah untuk {com} oleh {user}.")

def die() :
        print(f"Pacifista ngambek karena belum diperintah tetapi sudah disuruh berhenti!")
        exit()

d = dict()
d[''] = 0
d['cipherpol'] = 1
d['vegapunk'] = 2
d['gorosei'] = 3

serang = 0

auth = ''
prevcom = ''    
prevuser = ''
n = int(input())
for _ in range(n) :

        user, com = input().strip().split()
        
        if d[user] < d[auth] :
                fail(user, auth)
        
        elif prevcom == com :
                same(prevuser, prevcom)
                auth = user
        
        elif com=='berhenti' and not serang:
                die()

        else :
                if com == "serang" : serang = 1
                success(user, com)
                auth = user
                prevuser = user
                prevcom = com