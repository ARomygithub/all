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
int n,k;
ll a[mxn];
vi pr;

ll fastexpo(ll x, ll y) {
    ll ret = 1;
    while(y) {
        if(y&1) {
            if(x>mxn/ret) {
                ret = mxn+1;
                return ret;
            }
            ret *= x;
        }
        if(x>mxn/x) {
            if(y>1) {
                return mxn+1;
            }
            break;
        }
        x *= x;
        y >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    vi dp(mxn+1,0);
    rep(i,0,n) {
        ll u = a[i];
        ll v2 = 1,u2=1;
        for(int id=0;id<sz(pr)&&u>=1ll*pr[id]*pr[id];id++) {
            if((u%pr[id])==0) {
                int ct = 0;
                while((u%pr[id])==0) {
                    ct++;
                    u /= pr[id];
                }
                ct %= k;
                u2 *= fastexpo(pr[id],ct);
                if(ct>0) {
                    ll tmp = fastexpo(pr[id],k-ct);
                    if(tmp>mxn/v2) {
                        v2 = mxn+1;
                    } else {
                        v2 *= tmp;
                    }
                }
            }
        }
        if(u>1) {
            u2 *= u;
            ll tmp = fastexpo(u,k-1);
            if(tmp>mxn/v2) {
                v2 = mxn+1;
            } else {
                v2 *= tmp;
            }
        }
        if(v2<=mxn) {
            ans += dp[v2];
        }
        dp[u2]++;
    }
    cout <<ans <<"\n";
}

void init() {
    vector<bool> iscomp(mxn+1,0);
    rep(i,2,mxn+1) {
        if(!iscomp[i]) {
            pr.push_back(i);
            for(ll j=i*2;j<=mxn;j+=i) {
                iscomp[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}