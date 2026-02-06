#include <bits/stdc++.h>
// #define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
using ll = long long;
// const ll mod = 3006703054056749;
const ll mod = 1e9+7;
const int mxn = 2e5;
ll pw[mxn+1];

#define rep(i, a, b) for(int i = a; i < (b);i++)
#define per(i, a, b) for(int i= a; i > (b);i--) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n);
    b[0] = 0;
    int j = 0;
    rep(i,1,n+1) {
        b[0] = (b[0] + pw[j]*a[i%n]%mod)%mod;
        j++;
    }
    b[0] = b[0]*inv((pw[j]-1+mod)%mod)%mod;
    // what_is(b[0]);
    per(i,n-1,0) {
        b[i] = b[(i+1)%n]*2-a[(i+1)%n];
        // what_is(b[i]);
    }
    bool ok = 1;
    ll sb = 0, sa = 0;
    rep(i,0,n) {
        sb += b[i];
        sa += a[i];
        if(b[i]<0) {
            cout <<"-1\n";
            return;
        }
    }
    if(sb!=sa) {
        cout <<"-1\n";
        return;
    }
    ll ans = 1e18;
    rep(i,0,n) {
        min_self(ans, b[i]);
    }
    ll ans2 = 0;
    rep(i,0,n) {
        ans2 += b[i]-ans;
    }
    cout <<ans2 <<"\n";
}

void init() {
    pw[0] = 1;
    rep(i,1,mxn+1) {
        pw[i] = pw[i-1]*2%mod;
    }
}

signed main()
{
    int t;
    t = 1;
    cin >> t;
    init();
    while(t--)
    {
        solve();
    }
}