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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int q;

struct UF {
    vi e, val;
    UF(int n) : e(n, -1), val(n,0) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { 
        if(e[x]<0) {
            return x;
        } else {
            int fex = find(e[x]);
            if(e[x]!=fex) {
                val[x] ^= val[e[x]];
                e[x] = fex;
            }
            return e[x];
        }
    }
    bool join(int a, int b, int x) {
        int l = a, r= b;
        a = find(a), b = find(b);
        x ^= val[l];
        x ^= val[r];
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        val[b] = x;
        return true;
    }
};

void solve() {
    cin >>q;
    UF uf(2*q+1);
    map<int,int> mp;
    mp[0] = 0;
    int id = 1;
    int ls = 0;
    rep(i,0,q) {
        int t; cin >>t;
        if(t==1) {
            int l,r,x; cin >>l >>r >>x;
            l ^= ls;
            r ^= ls;
            x ^= ls;
            if(l>r) swap(l,r);
            l--;
            if(!mp.count(l)) {
                mp[l] = id; id++;
            }
            if(!mp.count(r)) {
                mp[r] = id; id++;
            }
            uf.join(mp[l],mp[r],x);
        } else {
            int l,r; cin >>l >>r;
            l ^= ls;
            r ^= ls;
            if(l>r) swap(l,r);
            l--;
            if(!mp.count(l)) {
                mp[l] = id; id++;
            }
            if(!mp.count(r)) {
                mp[r] = id; id++;
            }
            int l1 = uf.find(mp[l]);
            int l2 = uf.find(mp[r]);
            if(l1!=l2) {
                cout <<"-1\n";
                ls = 1;
            } else {
                ls = uf.val[mp[l]]^uf.val[mp[r]];
                cout <<ls <<"\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}