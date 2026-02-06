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

const int mxn=3e5, mxa=3e5;
const ll mod = 998244353;
int n,m;
ll d[mxn];
ll fct[mxa+1],ifc[mxa+1],iv[mxa+1];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>d[i];
    }
    ll s = 0;
    rep(i,0,n) {
        s += d[i];
    }
    int r = 0;
    ll sn = 0;
    int k = 0;
    rep(l,0,n-1) {
        while(r<n-1 && (sn+d[r])*2 <= s) {
            sn += d[r];
            r++;
        }
        if(sn*2==s) {
            k++;
        }
        if(l==r) {
            r++;
        } else {
            sn -= d[l];
        }
    }
    ll ans = 0;
    rep(x,0,k+1) {
        if(x>m) continue;
        ll tmp = C(k,x)*C(m,x)%mod;
        tmp = tmp*fct[x]%mod;
        tmp = tmp*fastexpo(m-x,n-k*2)%mod;
        ll tmp2 = 1ll*(m-x)*(m-x-1)%mod;
        tmp = tmp*fastexpo(tmp2, k-x)%mod;
        ans = (ans + tmp)%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}