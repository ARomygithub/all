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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5, mxs=700;
ll n,x,y,s,t;

void solve() {
    cin >>n >>x >>y >>s;
    ll a = x/y, b = x%y;
    s -= b*n;
    if(s<0 || (s%y)!=0) {
        cout <<"NO\n";
        return;
    }
    s /=y;
    vector<int> dp(s+1,1e9);
    dp[0] = 0;
    vector<int> last(s+1,-1);
    int si = 0;
    vector<int> vs;
    rep(i,1,mxs) {
        si +=i;
        if(si>s) break;
        dp[si] = i+1;
        vs.push_back(si);
        last[si] = i+1;
    }
    rep(i,2,s+1) {
        rep(j,0,sz(vs)) {
            if(vs[j]>=i) break;
            if(dp[i] > dp[i-vs[j]]+j+2) {
                dp[i] = dp[i-vs[j]]+j+2;
                last[i] = j+2;
            }
        }
    }
    rep(i,0,n) {
        ll temp = 1ll*(i+1)*(a*2+i)/2;
        if(temp>s) break;
        if(dp[s-temp]+i+1 <=n) {
            vector<ll> ans(n,0);
            vector<int> szi;
            int u = s-temp;
            while(u) {
                szi.push_back(last[u]);
                u -= vs[last[u]-2];
            }
            rep(j,0,i+1) {
                ans[j] = a+j;
            }
            int idx = i+1;
            for(int szii: szi) {
                rep(j,0,szii) {
                    ans[idx++] = j;
                }
            }
            cout <<"YES\n";
            rep(j,0,n) {
                cout <<ans[j]*y+b <<" \n"[j==n-1];
            }
            return;
        }
    }
    cout <<"NO\n";
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