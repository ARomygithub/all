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
int n,k,t;
ll b[mxn];

ll fastexpo(ll a, ll bb, ll md=mod) {
    ll ret = 1;
    while(bb) {
        if(bb&1) ret = ret*a%md;
        a = a*a%md;
        bb >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<ll> C(18);
    C[0] = 1;
    rep(i,1,18) {
        C[i] = C[i-1]*(k-1+i)%mod;
        C[i] = C[i]*inv(i)%mod;
        // cout <<C[i] <<" ";
    }
    vector<ll> ans(n);
    rep(i,0,n) {
        ans[i] = b[i];
        int u = i+1;
        int bit = 0;
        while(!((u>>bit)&1)) {
            bit++;
        }
        int idx = 1;
        rep(j,bit,18) {
            if((u>>j)&1) {
                u -= (1<<j);
                continue;
            }
            int temp = u + (1<<j);
            if(temp>n) break;
            b[temp-1] = (b[temp-1] - ans[i]*C[idx]%mod + mod)%mod;
            idx++;
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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