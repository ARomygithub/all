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
int n,k,t;

struct UF {
    vi e, ti;
    UF(int n) : e(n, -1), ti(n,1e9) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        min_self(ti[a], ti[b]);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve() {
    cin >>n >>k;
    UF uf(n);
    map<int,vector<pii>> mpx,mpy;
    rep(i,0,n) {
        int x,y,tim; cin >>x >>y >>tim;
        uf.ti[i] = tim;
        mpx[x].push_back({y,i});
        mpy[y].push_back({x,i});
    }
    for(auto& [xi,vx]: mpx) {
        sort(all(vx));
        rep(i,0,sz(vx)-1) {
            auto [yi0, id0] = vx[i];
            auto [yi1, id1] = vx[i+1];
            if(yi1-yi0<=k) {
                uf.join(id0,id1);
            } 
        }
    }
    for(auto& [yi, vy]: mpy) {
        sort(all(vy));
        rep(i,0,sz(vy)-1) {
            auto [xi0, id0] = vy[i];
            auto [xi1, id1] = vy[i+1];
            if(xi1-xi0<=k) {
                uf.join(id0,id1);
            }
        }
    }
    set<int> s;
    rep(i,0,n) {
        s.insert(uf.find(i));
    }
    vi a;
    for(auto si : s) {
        a.push_back(uf.ti[si]);
    }
    sort(all(a));
    int ans = sz(a)-1;
    int l = 0, r = ans-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(a[sz(a)-(mid+1)-1]<=mid) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}