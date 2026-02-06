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
int n,m,a,b,t;

void solve() {
    cin >>a >>b;
    cin >>n >>m;
    ll ans=min(1ll*n*a,1ll*n*b);
    if(1ll*(m+1)*b<=1ll*m*a) {
        cout <<1ll*n*b <<"\n";
    } else {
        if(a<=b) {
            int k = n/(m+1);
            int l = n%(m+1);
            ans = 1ll*k*m*a;
            ans +=1ll*l*a;
            cout <<ans <<"\n";
        } else {
            int k = n/(m+1);
            int l = n%(m+1);
            ans = 1ll*k*m*a;
            ans += 1ll*l*b;
            ll ans2 = 1ll*(k+1)*m*a;
            min_self(ans,ans2);
            cout <<ans <<"\n";
        }
    }
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