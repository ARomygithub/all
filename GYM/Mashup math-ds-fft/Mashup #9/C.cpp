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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int t;
ll a,b,c,d;

void solve() {
    cin >>a >>b >>c >>d;
    if(a-b*c > 0) {
        cout <<"-1\n";
        return;
    }
    ll ans = a;
    // ll i = 1;
    // while(a - b*clamp(i*d,1ll,c) >0) {
    //     ans += a - b*clamp(i*d,1ll,c);
    //     i++;
    // }
    ll k = (a+b-1)/b;
    k--;
    k /= d;
    ans += a*k - b*d*((k+1)*k/2);
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