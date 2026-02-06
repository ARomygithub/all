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

const int mxn=3e5, mxa=1e6;
const ll mod=998244353;
int n,q,t;
int a[mxn],b[mxn];
ll fct[mxa+1],iv[mxa+1],ifc[mxa+1];

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
    return fastexpo(a,mod-2);
}

void init() {
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
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<int> prefa(n,0), prefb(n,0);
    rep(i,0,n) {
        prefa[i] = (i>0?prefa[i-1]:0)+a[i];
    }
    rep(i,0,n) {
        prefb[i] = (i>0?prefb[i-1]:0)+b[i];
    }
    int m = prefb[n-1];
    vector<ll> prefC(m+1,0);
    ll iv2m = inv(fastexpo(2ll,m));
    rep(i,0,m+1) {
        prefC[i] = C(m,i)*iv2m%mod;
        prefC[i] = (prefC[i] +(i>0?prefC[i-1]:0ll))%mod;
        // cout <<prefC[i] <<"\n";
    }
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        int a1 = prefa[r]-(l>0?prefa[l-1]:0);
        int a2 = prefa[n-1]-a1;
        int b1 = prefb[r]-(l>0?prefb[l-1]:0);
        int sum = a1-a2+b1-1;
        if(sum<0) {
            cout <<"0\n";
        } else {
            int bts = min(m,sum);
            cout <<prefC[bts] <<" \n"[q==0];
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