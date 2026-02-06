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

const int mxn=1e5;
const ll mod = 998244353;
int n,m;

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

ll C(ll y, ll x) {
    // x small
    ll ret = 1;
    y %= mod;
    rep(i,1,x+1) {
        ret = ret*((y+1-i + mod)%mod)%mod;
        ret = ret*inv(i)%mod;
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    vector<ll> k(m),l(m),r(m);
    vector idx(m, vi());
    vector<bool> ada(n,0);
    rep(i,0,m) {
        cin >>l[i] >>r[i] >>k[i];
        rep(j,0,k[i]) {
            int u; cin >>u; u--;
            idx[i].push_back(u);
            ada[u] = 1;
        }
    }
    rep(i,0,n) {
        if(!ada[i]) {
            cout <<"infinity\n";
            return;
        }
    }
    if(m==1) {
        ll ans = 0;
        ans = (ans + C(r[0]+n-1,n-1))%mod;
        if(l[0]) {
            ans = (ans - C(l[0]-1+n-1,n-1) + mod)%mod;
        }
        cout <<ans <<"\n";
    } else {
        // disjoint
        int sm = 0;
        rep(j,0,m) {
            sm += k[j];
        }
        if(sm==n) {
            ll ans = 1;
            rep(j,0,m) {
                ll tmp = 0;
                tmp = (tmp + C(r[j]+k[j]-1,k[j]-1))%mod;
                if(l[j]) {
                    tmp = (tmp - (C(l[j]-1 + k[j]-1, k[j]-1)) + mod)%mod;
                }
                ans = ans*tmp%mod;
            }
            cout <<ans <<"\n";
            return;
        }
        cout <<"0\n"; // TODO
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}