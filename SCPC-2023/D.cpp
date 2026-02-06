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
ll n,m;

void solve() {
    cin >>n >>m;
    ll mn = m, mx = m*5;
    if(n<mn || n>mx) {
        cout <<"-1 -1\n";
        return;
    }
    ll ans1 = max(0ll, (n-m*4));
    ll ans2 = (n-m)/4;
    cout <<ans1 <<" " <<ans2 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}