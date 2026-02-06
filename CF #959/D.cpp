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

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

const int mxn=2e3;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> ans(n-1);
    UF uf(n);
    vector comp(n, vector<vector<int>>());
    rep(i,1,n) {
        comp[i].resize(i);
        rep(j,0,n) {
            comp[i][a[j]%i].push_back(j);
        }
    }
    per(i,n-1,0) {
        bool ok = 0;
        rep(j,0,i) {
            if(sz(comp[i][j])<2) continue;
            int u = comp[i][j][0];
            for(auto id: comp[i][j]) {
                if(uf.join(u,id)) {
                    ok = 1;
                    ans[i-1] = {u+1,id+1};
                    break;
                }
            }
            if(ok) break;
        }
        assert(ok);
    }
    cout <<"YES\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
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