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

const int mxn=1e3;
const ll mod = 998244353;
int n,m,t;
ll a[mxn];

vi topoSort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    for (auto& li : gr) for (int x : li) indeg[x]++;
    queue<int> q; // use priority_queue for lexic. largest ans.
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for (int x : gr[i])
            if (--indeg[x] == 0) q.push(x);
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector gr(n, vi());
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        gr[u].push_back(v);
    }
    auto topo = topoSort(gr);
    vi b(n,0);
    rep(tm,0,n-1) {
        bool ok = 0;
        per(i,sz(topo)-1,-1) {
            int u = topo[i]; 
            if(b[u] || a[u]) {
                ok = 1;
                if(b[u]) {
                    a[u] = (a[u]-1+mod)%mod;
                } else {
                    a[u]--;
                    if(a[u]>=mod) {
                        b[u] = 1;
                        a[u] %= mod;
                    }
                }
                for(int v: gr[u]) {
                    a[v]++;
                    if(a[v]>=mod) {
                        b[v] = 1;
                        b[v] %= mod;
                    }
                }
            }
        }
        if(!ok) {
            cout <<tm <<"\n";
            return;
        }
    }
    ll tm = n-1;
    vector<ll> dp(n,0);
    for(auto u : topo) {
        dp[u] = (dp[u]+ a[u])%mod;
        for(auto v: gr[u]) {
            dp[v] = (dp[v] + dp[u])%mod;
        }
    }
    rep(i,0,n) {
        if(sz(gr[i])==0) {
            tm = (tm + dp[i])%mod;
        }
    }
    cout <<tm <<"\n";
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