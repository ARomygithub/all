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

const int mxn=2e5;
const ll mod = 998244353;
int n,t;
int s[mxn];

ll fastexpo(ll a, ll b, ll md = mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%md;
        a = a*a%md;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

struct Nd {
    Nd* le=0; Nd* ri=0;
    int ct = 0;
};

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    map<int,int> mp;
    rep(i,0,n) {
        mp[s[i]]++;
    }
    ll sm = 0;
    for(auto& [k,v]: mp) {
        sm = (sm + 2ll*v*v)%mod;
        sm = (sm + 3ll*v*(n-v))%mod;
    }
    Nd* r = new Nd();
    function<void(int)> ad;
    ad = [&](int u) -> void {
        Nd* nu = r;
        (*nu).ct++;
        per(j,29,-1) {
            if((u>>j)&1) {
                if(!(nu->ri)) {
                    nu->ri = new Nd();
                }
                nu = nu->ri;
            } else {
                if(!(nu->le)) {
                    nu->le = new Nd();
                }
                nu = nu->le;
            }
            (*nu).ct++;
        }
    };
    rep(i,0,n) {
        ad(s[i]);
    }
    function<void(Nd*,int)> dfs;
    dfs = [&](Nd* nu, int u) -> void {
        if(u%2) {
            ll temp = 2ll*(nu->ct)*(nu->ct)%mod;
            sm = (sm + temp)%mod;
        }
        if(nu->ri) {
            dfs(nu->ri, u*2+1);
        }
        if(nu->le) {
            dfs(nu->le, u*2);
        }
    };
    dfs(r, 0);
    // cout <<sm <<"\n";
    ll bagi = inv(1ll*n*n*2%mod);
    sm = sm*bagi%mod;
    cout <<sm <<"\n";
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