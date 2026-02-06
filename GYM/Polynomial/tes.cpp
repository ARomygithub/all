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
int n;

void solve() {
    // cin >>n;
    vector<ll> a(18);
    ll p2 = 1;
    rep(i,0,18) {
        a[i] = p2*i*i*i;
        p2 *= 2;
        cout <<a[i] <<endl;
    }
    rep(i,4,18) {
        assert(a[i] == a[i-1]*8-a[i-2]*24+a[i-3]*32-a[i-4]*16);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}