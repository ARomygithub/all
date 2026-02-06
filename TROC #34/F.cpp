#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e6, mxa=1e6;
const ll mod=1e9+7;
int n,k;
ll fct[mxa+1],ifc[mxa+1],iv[mxa+1];

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
    cin >>n >>k;
    ll ans=0;
    ll c111= (C(n-2,k)+C(n-2,k-1))%mod;
    c111 = (c111+C(n-2,k-2))%mod;
    ll c121 = (C(n-2,k)+C(n-2,k-1)*2)%mod;
    c121 = (c121+C(n-2,k-2))%mod;
    ll temp1 = 2ll*fct[n-1]*c111%mod;
    ll temp2 = fct[n-1]*(n-2)%mod;
    temp2 = temp2*c121%mod;
    ans = (temp1+temp2)%mod;
    if(n>2) {
        ll temp21 = fct[n-1]*c111%mod;
        ll temp22 = 0;
        for(int i=1;i<=n-3;i++) {
            temp22 = (temp22+ 1ll*i*(n-2-i))%mod;
        }
        temp22 = temp22*c121%mod;
        temp22 = temp22*fct[n-3]%mod;
        temp22 = temp22*2%mod;
        ll tempp = (temp21+temp22)%mod;
        tempp = tempp*(n-2)%mod;
        ans = (ans+tempp)%mod;
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