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

const int mxn=5e5;
const ll mod=1e9+7;
int n,m;
ll c[mxn],k;

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return ret;
}

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};
using lpii = pair<ll,pii>;

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>c[i];
    }
    vector<lpii> e;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        e.push_back({c[u]^c[v],{u,v}});
    }
    sort(all(e));
    ll ans = 0;
    RollbackUF ruf(n);
    if(!(sz(e) && e[0].fi==0)) {
        ans = (ans + fastexpo(2,n))%mod;
    } else {
        // cek bipartite
        vector adj(n, vi());
        rep(i,0,sz(e)) {
            if(e[i].fi!=0) break;
            auto [u,v] = e[i].se;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi cl(n,-1);
        vi v0,v1;
        function<bool(int)> dfs;
        dfs = [&](int u) -> bool {
            for(int v: adj[u]) {
                if(cl[v]==-1) {
                    cl[v] = 1-cl[u];
                    if(cl[v]==0) {
                        v0.push_back(v);
                    } else {
                        v1.push_back(v);
                    }
                    bool ok = dfs(v);
                    if(!ok) return 0;
                } else {
                    if(cl[v]==cl[u]) {
                        return 0;
                    }
                }
            }
            return 1;
        };
        rep(i,0,n) {
            if(cl[i]==-1) {
                v0.clear(); v1.clear();
                cl[i] = 0;
                v0.push_back(i);
                bool ok = dfs(i);
                if(!ok) {
                    cout <<"0\n";
                    return;
                }
                rep(j,0,sz(v0)-1) {
                    ruf.join(v0[j],v0[j+1]);
                }
                rep(j,0,sz(v1)-1) {
                    ruf.join(v1[j],v1[j+1]);
                }
            }
        }
    }
    set<int> sl;
    rep(i,0,n) {
        sl.insert(ruf.find(i));
    }
    int awl = sz(sl);
    ll sisa = (fastexpo(2,k)-1+mod)%mod;
    int t = ruf.time();
    for(int i=0;i<sz(e);) {
        if(e[i].fi==0) {
            i++;
            continue;
        }
        int j = i;
        while(j<sz(e) && e[j].fi==e[i].fi) {
            j++;
        }
        sisa = (sisa - 1+mod)%mod;
        int szi = awl;
        rep(i2,i,j) {
            auto [u,v] = e[i2].se;
            if(ruf.join(u,v)) {
                szi--;
            }
        }
        ans = (ans + fastexpo(2,szi))%mod;
        ruf.rollback(t);
        i = j;
    }
    ans = (ans + fastexpo(2,awl)*sisa%mod)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}