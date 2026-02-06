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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,b;
int a[mxn];

void solve() {
    cin >>b >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = 0;
    rep(i,0,n-1) {
        ans = (ans + a[i]*b%2)%2;
    }
    ans = (ans + a[n-1]%2)%2;
    if(ans) {
        cout <<"odd\n";
    } else {
        cout <<"even\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}