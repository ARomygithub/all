#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e3;
const ll mod=1e9+7;
int n;
int a[mxn+1];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    a[n] = 2e9;
    ll ans=fastexpo(2ll,n);
    ans = (ans-1-n+mod)%mod;
    for(int i=1;i<n;i++) {
        for(int j=i+1;j+1<n;j++) {
            int y = a[j]-a[i];
            int it2 = lower_bound(a,a+n+1,a[j]+y)-a;
            int it1 = lower_bound(a,a+n+1,a[i]-y)-a;
            ll temp = (fastexpo(2ll,i)-fastexpo(2ll,it1)+mod)%mod;
            temp = temp*((fastexpo(2ll,n-j-1)-fastexpo(2ll,n-it2)+mod)%mod)%mod;
            ans = (ans+temp)%mod;
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