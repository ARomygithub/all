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

const int mxn=65535;
const ll mod=998244353;
int n,q,t;
int a[mxn+1],p[mxn+1];
ll val[mxn+1];
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
ll pw;
map<int,int> mp,imp;

void dfs(int u, int pa=-1) {
    if(u*2<=n) {
        ll temp = 1;
        val[u] = pw*u%mod;
        dfs(u*2, u);
        dfs(u*2+1, u);
        temp = val[u*2]*val[u*2+1]%mod;
        val[u] = (val[u]+temp)%mod;
    } else {
        val[u] = pw*u%mod;
    }
}

void dfs2(int u, int& id) {
    // debug() <<imie(u) imie(id);
    if(u*2<=n) {
        val[u] = pw*p[id]%mod;
        mp[id] = u;
        imp[u] = id;
        id++;
        dfs2(u*2, id);
        dfs2(u*2+1, id);
        ll temp = val[u*2]*val[u*2+1]%mod;
        val[u] = (val[u]+temp)%mod;
    } else {
        val[u] = pw*p[id]%mod;
        mp[id] = u;
        imp[u] = id;
        id++;
    }
}

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void recalc(int u, int ol, int nw) {
    // debug() <<"recalc";
    ll oll = val[u];
    val[u] = (val[u] - (pw*ol)%mod + (pw*nw)%mod + mod)%mod;
    // debug() <<imie(u) imie(oll) imie(val[u]);
    while(u>1) {
        ll up = u/2;
        ll cur = (pw*p[imp[up]])%mod;
        ll temp = (val[up] - cur + mod)%mod;
        temp = temp*inv(oll)%mod;
        temp = temp*val[u]%mod;
        oll = val[up];
        val[up] = (cur+temp)%mod;
        u = up;
        // debug() <<imie(u) imie(oll) imie(val[u]);
    }
}

void solve() {
    cin >>n >>q;
    rep(i,2,n+1) {
        cin >>a[i];
    }
    rep(i,1,n+1) {
        cin >>p[i];
    }
    pw = 1 + (rng64()%(mod-1));
    dfs(1,-1);
    ll val0 = val[1];
    int id = 1;
    dfs2(1,id);
    // debug() <<imie(mp);
    while(q--) {
        int x,y; cin >>x >>y;
        if(x<y) {
            swap(x,y);
        }
        recalc(mp[x], p[x], p[y]);
        recalc(mp[y], p[y], p[x]);
        swap(p[x],p[y]);
        if(val[1]==val0) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
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