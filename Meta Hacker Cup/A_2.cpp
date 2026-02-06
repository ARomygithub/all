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

const int mxn=1e5;
ll a,b,c,t;

void solve() {
    cin >>a >>b >>c;
    ll ans=0;
    ll d1 = c/b;
    max_self(ans, d1*2-1);
    if(c>=a) {
        ll ans2 = 1;
        c -=a;
        ll s2,d2;
        if(a*2 <= b) {
            d2 = 0;
            s2 = c/a;
        } else {
            d2 = c/b;
            s2 = ((c%b)>=a);
        }
        ans2 +=s2+d2*2;
        max_self(ans,ans2);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}