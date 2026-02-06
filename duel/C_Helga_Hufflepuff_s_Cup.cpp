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

const int mxn=1e5,mxx=10;
const ll mod = 1e9+7;
int n,m,k,x,t;
vi adj[mxn];
ll dp[mxn][mxx+1][3];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void dfs(int u, int p=-1) {
    // debug() <<imie(u);
    vector vc(3, vector<ll>(x+1,0));
    vc[0][0] = 1;
    vc[1][0] = 1;
    vc[2][0] = 1;
    // bool leaf = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        // leaf = 0;
        dfs(v,u);
        vector vc_new(3, vector<ll>(x+1,0));
        per(i,x,-1) {
            rep(j,0,i+1) {
                vc_new[0][i] = (vc_new[0][i] + vc[0][i-j]*dp[v][j][0]%mod)%mod; 
                ll sm = (dp[v][j][0]+dp[v][j][1]+dp[v][j][2])%mod;
                vc_new[1][i] = (vc_new[1][i] +vc[1][i-j]*sm%mod)%mod;
                ll sm2 = (dp[v][j][0]+dp[v][j][2])%mod;
                vc_new[2][i] = (vc_new[2][i] +vc[2][i-j]*sm2%mod)%mod;
            }
        }
        vc.swap(vc_new);
        // debug() <<imie(u) imie(v);
        // debug() <<imie(vc);
    }
    // debug() <<imie(u);
    // rep(j,0,x+1) {
    //     vc[1][j] = (vc[1][j] - vc[0][j]+mod)%mod;
    // }
    // if(leaf) {

    // }
    // debug() <<imie(u);
    rep(j,0,x+1) {
        dp[u][j][0] = 1ll*(k-1)*vc[1][j]%mod;
        // debug() <<imie(j) imie(dp[u][j][0]);
    }
    rep(j,0,x) {
        dp[u][j+1][1] = vc[0][j];
        // debug() <<imie(j) imie(dp[u][j][1]);
    }
    rep(j,0,x+1) {
        dp[u][j][2] = 1ll*(m-k)*vc[2][j]%mod;
        // debug() <<imie(j) imie(dp[u][j][2]);
    }
}

void solve() {
    cin >>n >>m;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >>k >>x;
    if(k==1) {
        if(n==1) {
            cout <<m <<"\n";
        } else {
            ll ret = fastexpo(m-1,n);
            cout <<ret <<"\n";
        }
        return;
    }
    dfs(0,-1);
    ll ans = 0;
    rep(j,0,x+1) {
        rep(j2,0,3) {
            ans = (ans + dp[0][j][j2])%mod;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}