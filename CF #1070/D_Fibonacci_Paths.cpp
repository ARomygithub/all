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
const ll mod = 998244353;
int n,m,t;
ll a[mxn];
using pli = pair<ll,int>;

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> ed(m);
    rep(i,0,m) {
        cin >>ed[i].fi >>ed[i].se; ed[i].fi--,ed[i].se--;
    }
    sort(all(ed), [&](const pii& edi, const pii& edj) -> bool {
        auto [iu,iv] = edi;
        auto [ju,jv] = edj;
        return pll{a[iv],a[iu]} < pll{a[jv],a[ju]};
    });
    vector adj(n, vector<pli>());
    rep(i,0,m) {
        auto [u,v] = ed[i];
        adj[v].push_back({a[u],i});
    }
    // rep(i,0,n) {
    //     sort(all(adj[i]));
    // }
    ll ans = 0;
    vector<ll> dp(m,1);
    vector vmp(n, map<ll,ll>());
    for(int i = m-1;i>=0;i--) {
        // debug() <<imie(ed[i]);
        // debug() <<imie(dp[i]);
        auto [u,v] = ed[i];
        if(vmp[v].count(a[u])) {
            dp[i] = (dp[i] + vmp[v][a[u]])%mod;
        }
        ans = (ans + dp[i])%mod;
        ll prv = a[v]-a[u];
        vmp[u][prv] = (vmp[u][prv] + dp[i])%mod;
        // auto it = lower_bound(all(adj[u]), pli{prv,-1});
        // while(it!=adj[u].end()) {
        //     if(it->fi != prv) break;
        //     auto id = it->se;
        //     dp[id] = (dp[id] + dp[i])%mod;
        //     it++;
        // }
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