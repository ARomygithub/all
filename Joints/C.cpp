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

const int mxn=1e5;
ll n,k;
int phi[mxn+1];
ll mod;
void totient() {
  for (int i = 1; i <= mxn; i++) phi[i] = i;
  for (int i = 2; i <= mxn; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= mxn; j += i) phi[j] -= phi[j] / i;
    }
  }
}

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
    cin >>n >>k;
    ll temp = fastexpo(10ll,100,phi[phi[n]]);
    ll gcd = __gcd(k,)
    ll p = fastexpo(k,temp,phi[n]);
    if((k%phi[n]) == 0) {
        p = 0;
    }
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans = (ans+fastexpo(i,p,n));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    totient();
    solve();
}