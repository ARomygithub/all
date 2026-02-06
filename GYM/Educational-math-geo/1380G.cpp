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

const int mxn=3e5+5;
const ll mod = 998244353;
int n;
int c[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%md;
        a = a*a%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>c[i];
    }
    sort(c+1,c+n+1,greater<int>());
    vector<ll> pref(n+1,0);
    rep(i,1,n+1) {
        pref[i] = pref[i-1]+c[i];
    }
    vector<ll> ans(n+1,0);
    rep(i,1,n+1) {
        for(int l=1,mul=0; l<=n; l+=i,mul++) {
            int r = min(l+i-1,n);
            ans[i] = (ans[i] + (pref[r]-pref[l-1])*mul%mod)%mod; 
        }
    }
    ll ivn = fastexpo(n,mod-2);
    rep(i,1,n+1) {
        ans[i] = ans[i]*ivn%mod;
        cout <<ans[i] <<" \n"[i==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}