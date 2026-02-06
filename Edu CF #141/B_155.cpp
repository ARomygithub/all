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

const int mxn=3e5;
int n,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n;
    ll suma=0, sumb=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        suma +=a[i];
    }
    for(int i=0;i<n;i++) {
        cin >>b[i];
        sumb +=b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    ll ans = min(suma+1ll*b[0]*n,sumb+1ll*a[0]*n);
    cout <<ans <<"\n";
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