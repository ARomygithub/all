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
int n,s,k;

void solve() {
    cin >>n >>s >>k;
    int m = 0;
    int x = n+1;
    while(x>1) {
        m++;
        x /= 2;
    }
    if(k>m) {
        cout <<"0\n";
        return;
    }
    ll ans = C(s-1,k)*C(n+1-s,m-k)%mod;
    ll tmp = 1; // ngatur n-m sisa
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}