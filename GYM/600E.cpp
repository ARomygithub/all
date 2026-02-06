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
    vector<map<int,int>> vmp;
    vector<int> mx;
    vector<ll> ans;
    UF(int n) : e(n, -1), vmp(n), mx(n), ans(n) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        for(auto [k,v]: vmp[b]) {
            if(vmp[a].count(k)) {
                vmp[a][k] += v;
            } else {
                vmp[a][k] = v;
            }
            if(vmp[a][k] > mx[a]) {
                mx[a] = vmp[a][k];
                ans[a] = k;
            } else if(vmp[a][k]==mx[a]) {
                ans[a] += k;
            }
        }
        vmp[b].clear();
        return true;
    }
};

const int mxn=1e5;
int n;
vector<int> adj[mxn];
int c[mxn];
ll ans2[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>c[i];
    }
    int rt = 0;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    UF uf(n);
    function<void(int,int)> dfs;
    dfs = [&](int u, int p=-1) -> void {
        uf.vmp[u][c[u]] = 1;
        uf.ans[u] = c[u];
        uf.mx[u] = 1;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs(v, u);
            uf.join(u, v);
        }
        ans2[u] = uf.ans[uf.find(u)];
    };
    dfs(rt, -1);
    rep(i,0,n) {
        cout <<ans2[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}