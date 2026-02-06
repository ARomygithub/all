#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxa=2e5;
const ll mod=1e9+7;
ll n,k;


ll fastexpo(ll a, ll b, ll m) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%m;}
        a = (a*a)%m;
        b >>=1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>k;
    if(n==1) {
        cout <<k;
    } else if(n%2==1){
        ll ans= fastexpo(k-1,n,mod)-k+1;
        if(ans<0) {
            ll temp=(-1ll*ans)/mod; temp++;
            ans += temp*mod;
        }
        cout <<ans%mod;
    } else {
        ll ans= fastexpo(k-1,n,mod)+k-1;
        if(ans<0) {
            ll temp=(-1ll*ans)/mod; temp++;
            ans += temp*mod;
        }
        cout <<(ans)%mod;
    }
}
