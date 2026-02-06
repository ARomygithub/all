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
int n,m;
int c[mxn];
vector<pii> adj[mxn];
vi adj2[mxn];

void solve() {
    cin >>n >>m;
    vi ct(m+1,0);
    rep(i,0,n) {
        cin >>c[i];
        ct[c[i]]++;
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        if(c[u]==c[v]) {
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        } else {
            adj[u].push_back({c[v],v});
            adj[v].push_back({c[u],u});
        }
    }
    rep(i,0,n) {
        sort(all(adj[i]));
        for(int j=0;j<sz(adj[i]);) {
            int k = j;
            while(k<sz(adj[i]) && adj[i][k].fi==adj[i][j].fi) {
                k++;
            }
            int u = adj[i][j].se;
            rep(l,j+1,k) {
                int v = adj[i][l].se;
                adj2[u].push_back(v);
                adj2[v].push_back(u);
            }
            j = k;
        }
    }
    vi ans(m+1, -1);
    vector<bool> vis(n, 0);
    rep(i,0,n) {
        if(ans[c[i]]!=-1) continue;
        int ctc = 0;
        int ci = c[i];
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(sz(q)) {
            auto u = q.front(); q.pop();
            // debug() <<imie(u);
            ctc++;
            for(auto& v: adj2[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        if(ctc==ct[ci]) {
            ans[ci] = 0;
        } else {
            ans[ci] = 1;
        }
    }
    rep(i,1,m+1) {
        if(ans[i]==-1) ans[i]=0;
    }
    rep(i,1,m+1) {
        cout <<ans[i] <<" \n"[i==m];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}