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

const int mxn=15;
int n,k;
ll x[mxn],y[mxn];
using lpll = pair<ll,pll>;

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    ll ans = -1;
    vector<lpll> v;
    rep(i,0,n) {
        rep(j,i+1,n) {
            ll ds = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            v.push_back({ds,{i,j}});
        }
    }
    sort(all(v));
    ll l = 0, r = sz(v);
    while(l<=r) {
        ll mid = (l+r)/2;
        vector ed(n, vector<bool>(n,0));
        rep(i,0,mid) {
            auto [val, uv] = v[i];
            auto [a,b] = uv;
            ed[a][b] = 1;
        }
        vector<ll> dp(1<<n, k+1);
        rep(bit,0,1<<n) {
            bool ok = 1;
            rep(i,0,n) {
                rep(j,i+1,n) {
                    if(((bit>>i)&1) && ((bit>>j)&1)) {
                        ok = ok && ed[i][j];
                    }
                    if(!ok) break;
                }
                if(!ok) break;
            }
            if(ok) {
                dp[bit] = 1;
            } else {
                for(int st = bit; st; ) {
                    --st &= bit;
                    min_self(dp[bit], dp[st]+dp[bit-st]);
                }
            }
        }
        if(dp[(1<<n)-1]<=k) {
            ans = mid>0?v[mid-1].fi : 0;
            r = mid-1;
        } else {
            l = mid+1;
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