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

const int mxn=1e5,mxa=8e5;
const ll mod=998244353;
int n,m,t;
ll fct[mxa+1],iv[mxa+1],ifc[mxa+1];

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
    int bwh=(n-1)/2;
    int atas=n/2;
    ll ans=0;
    for(int i=1;i<=atas;i++) {
        ans = (ans+C(m+i+n-1,n-1))%mod;
    }
    // cout <<ans <<"\n";
    for(int i=1;i<=atas*2-1;i++) {
        ll temp=C(n,i);
        ll i12 = (i+2)/2;
        // ll temp2 = (C(m+atas,i)-C(m+i12-1,i)+mod)%mod;
        if(m+atas>=i) {
            ll temp2 = C(m+atas,i);
            if(m+i12-1>=i) {
                temp2 = (temp2 - C(m+i12-1,i)+mod)%mod;
            }
            temp = temp*temp2%mod;
            // cout <<temp <<"\n";
            ans = (ans-temp+mod)%mod;
        } else {
            break;
        }
        
        // if(i12>=atas) {
        //     temp2 = (C(m+atas,i)-C(m,i)+mod)%mod;
        // }
    }
    // cout <<ans <<"\n";
    for(int i=1;i<=bwh;i++) {
        if(i>m) break;
        ans = (ans+C(m-i+n-1,n-1))%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init_fac();
    while(t--) {
        solve();
    }
}