#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

struct UF {
    vi e;
    UF(int n): e(n, -1) {}
    bool sameSet(int a, int b) { return find(a)==find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x]<0 ? x: e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b= find(b);
        if(a==b) return false;
        if(e[a] > e[b]) swap(a,b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

const int mxn = 3e5;
int n,q;

void solve() {
    cin >>n >>q;
    UF ufr(n), ufb(n), uft(n);
    int usedr = 0, usedb = 0, used = 0;
    int totr = 0, totb = 0, tot = 0;
    while(q--) {
        int qt,u,v; cin >>qt >>u >>v;
        u--,v--;
        tot++;
        if(uft.join(u,v)) {
            used++;
        }
        if(qt==1) {
            totr++;
            if(ufr.join(u,v)) {
                usedr++;
            }
        } else {
            totb++;
            if(ufb.join(u,v)) {
                usedb++;
            }
        }
        int rm = totr-usedr;
        int bm = totb - usedb;
        int nn = tot - used - rm - bm;
        int ans = min(rm,bm);
        int mx = max(rm,bm) - min(rm,bm);
        if(mx<=nn) {
            ans += (mx+nn)/2;
        } else {
            ans += nn;
        }
        cout <<ans*2 <<"\n";
    }
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}