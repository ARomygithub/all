#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
int n,q;

struct UF {
    vi e, box;
    map<int,int> boxInst;
    UF(int n) : e(n, -1) {
        box.resize(n);
        iota(box.begin(), box.end(), 0);
        rep(i,0,n) {
            boxInst[i] = i;
        }
    }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    void setBox(int val, int boxi) {
        if(boxInst[boxi]<0) {
            box[val] = boxi;
            boxInst[boxi] = val;
        } else {
            join(boxi, val);
        }
    }
    int getBox(int val) {
        return box[find(val)];
    }
    void join(int a, int b) {
        int instA = boxInst[a], instB = boxInst[b];
        if(instA==-1 && instB==-1) {
            return;
        } else if(instA==-1) {
            int leadB = find(instB);
            box[leadB] = a;
            boxInst[b] = -1;
            boxInst[a] = leadB;
            return;
        } else if(instB==-1) {
            return;
        }
        int leadA = find(instA), leadB = find(instB);
        if (leadA == leadB) return;
        box[leadB] = a;
        boxInst[b] = -1;
        if (e[leadA] > e[leadB]) swap(leadA, leadB);
        e[leadA] += e[leadB]; e[leadB] = leadA;
        return;
    }
};

void solve() {
    cin >>n >>q;
    int k = n;
    UF uf(n+q);
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x,y; cin >>x >>y; x--,y--;
            uf.join(x,y);
        } else if(qt==2) {
            int x; cin >>x; x--;
            uf.setBox(k, x);
            k++;
        } else {
            int x; cin >>x; x--;
            cout <<uf.getBox(x)+1 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}