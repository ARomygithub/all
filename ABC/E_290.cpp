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

const int mxn=2e5;
int n;
int a[mxn], ct[mxn+1];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        ct[a[i]]++;
    }
    ll ans = 0;
    int temp = n;
    for(int i=0;i<(n-1-i);i++,temp-=2) {
        ans +=1ll*(temp-ct[a[i]])*(i+1);
        ans +=1ll*(temp-ct[a[n-1-i]])*(i+1);
        ans -=1ll*(a[i]!=a[n-1-i])*(i+1);
        ct[a[i]]--;
        ct[a[n-1-i]]--;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}