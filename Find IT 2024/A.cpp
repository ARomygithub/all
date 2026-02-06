#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const int mxn=5e3;
int n,k,t;
vector<vector<pii>> adj(mxn);
vector<ll> ct[mxn], ls[mxn];
map<int,vector<ll>> last[mxn];
set<int> bom;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vector<pii>>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vector<pii>>& C, int v, int par) {
        time[v] = T++;
        for (auto [w,y] : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

int d0[mxn];
void dfs(int u, int p=-1) {
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        d0[v] = d0[u] + w;
        dfs(v,u);
    }
}

void solve() {
    cin >>n >>k >>t;
    rep(i,0,k) {
        int bomi; cin >>bomi; bomi--;
        bom.insert(bomi);
    }
    adj.resize(n);
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    LCA lca(adj);
    dfs(0);
    // cout <<"tes" <<endl;
    auto solve_aux = [&]() -> void {
        vector<pii> vec;
        for(auto bomi: bom) {
            vec.push_back({lca.time[bomi],bomi});
        }
        if(!bom.count(0)) {
            vec.push_back({lca.time[0],0});
        }
        set<pii> aux;
        sort(vec.begin(),vec.end());
        rep(i,0,sz(vec)) {
            aux.insert(vec[i]);
            if(i+1<sz(vec)) {
                int u = lca.lca(vec[i].se,vec[i+1].se);
                aux.insert({lca.time[u], u});
            }
        }
        stack<int> st;
        vector adj2(n, vector<int>());
        for(auto [ti, u]: aux) {
            if(sz(st)) {
                while(lca.lca(st.top(), u) != st.top()) {
                    st.pop();
                }
                adj2[st.top()].push_back(u);
                adj2[u].push_back(st.top());
                st.push(u);
            } else {
                st.push(u);
            }
        }
        /* DFS */
        function<void(int,int)> dfs_aux;
        dfs_aux = [&](int u, int p) -> void {
            // cout <<"dfs " <<u <<endl;
            ct[u].push_back(0ll);
            for(auto v: adj2[u]) {
                if(v==p) continue;
                dfs_aux(v, u);
                int cur = (bom.find(v)!=bom.end());
                // last[u][u2] + ct[v]
                // last[u][v] + ct[u]
                // ct[u] += ct[v]
                // O(k^3)
                int w = d0[v]-d0[u];
                vector<ll> lv;
                for(auto& [u2,lu2]: last[u]) {
                    vector<ll> lu2_new(sz(lu2)+sz(ct[v])-1+cur,1e18);
                    lu2_new[0] = 0;
                    rep(i,0,sz(lu2)) {
                        rep(j,0,sz(ct[v])) {
                            min_self(lu2_new[i+j+cur], lu2[i]+ct[v][j]+w*2);
                        }
                    }
                    lu2.swap(lu2_new);
                    // if(sz(lv)==0) {
                    //     lv.resize(sz(lu2), 1e18);
                    // }
                }
                // if(sz(lv)==0) {
                //     lv.resize(sz(ct[v])+cur, 1e18);
                // }
                lv.resize(sz(ct[u])+sz(ls[v])-1+cur,1e18);
                lv[0] = 0;
                rep(i,0,sz(ct[u])) {
                    rep(j,0,sz(ls[v])) {
                        min_self(lv[i+j+cur], ct[u][i]+ls[v][j]+w);
                    }
                }
                last[u][v] = lv;
                vector<ll> ctu_new(sz(ct[u])+sz(ct[v])-1+cur,1e18);
                ctu_new[0] = 0;
                rep(i,0,sz(ct[u])) {
                    rep(j,0,sz(ct[v])) {
                        min_self(ctu_new[i+j+cur], ct[u][i]+ct[v][j]+w*2);
                    }
                }
                ct[u].swap(ctu_new);
            }
            ls[u].resize(sz(ct[u]),1e18);
            ls[u][0] = 0;
            for(auto v: adj2[u]) {
                if(v==p) continue;
                auto& lv = last[u][v];
                rep(i,0,sz(lv)) {
                    min_self(ls[u][i], lv[i]);
                }
            }
            // debug() <<imie(u);
            // debug() <<imie(ct[u]);
            // debug() <<imie(ls[u]);
        };
        dfs_aux(0,-1);
    };
    solve_aux();
    // cout <<"tes" <<endl;
    int ans = 0;
    int bom0 = (bom.count(0));
    rep(i,0,sz(ls[0])) {
        // cout <<ls[0][i] <<endl;
        if(ls[0][i] <= t) {
            max_self(ans, i+bom0);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}