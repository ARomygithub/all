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

const int mxn=2025;
const ll mod = 998244353;
int n,m;
vi adj[mxn],adj2[mxn];

void solve() {
    cin >>n >>m;
    ll ans = 1;
    vi out(n,0);
    rep(i,0,n) {
        int ai; cin >>ai; ai--;
        adj[ai].push_back(i);
        adj2[i].push_back(ai);
        out[ai]++;
    }
    set<int> blm;
    rep(i,0,n) {
        blm.insert(i);
    }
    vector dp(n, vector<ll>(m+1,0));
    set<pii> s;
    rep(i,0,n) {
        s.insert({out[i],i});
    }
    auto calc = [&](vector<ll>& dpi, vi& adji) -> void {
        rep(i,1,m+1) {
            dpi[i] = 1;
            for(auto& v: adji) {
                dpi[i] = dpi[i]*dp[v][i]%mod;
            }
        }
        rep(i,2,m+1) {
            dpi[i] = (dpi[i] + dpi[i-1])%mod;
        }
    };
    while(sz(s)) {
        if((*s.begin()).fi==0) {
            int id = s.begin()->se;
            s.erase(s.begin());
            calc(dp[id], adj[id]);
            blm.erase(id);
            for(auto v: adj2[id]) {
                s.erase({out[v],v});
                out[v]--;
                s.insert({out[v],v});
            }
        } else {
            break;
        }
    }
    while(sz(blm)) {
        int u = *blm.begin();
        set<int> cur;
        function<void(int)> dfs;
        dfs = [&](int x) -> void {
            blm.erase(x);
            cur.insert(x);
            for(int v: adj[x]) {
                if(blm.count(v)) {
                    dfs(v);
                }
            }
        };
        vi to;
        dfs(u);
        for(auto curi : cur) {
            for(int v: adj[curi]) {
                if(!cur.count(v)) {
                    to.push_back(v);
                }
            }
        }
        // debug() <<imie(u) imie(to);
        calc(dp[u], to);
        // debug() <<imie(dp[u]);
        ans = ans*dp[u][m]%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}