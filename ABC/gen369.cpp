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

const int mxn=2e5;
int n,m,k;
int r[mxn],c[mxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int a, int b) {
    return a + rng()%(b-a+1);
}

void solve() {
    n = 2e5, m=2e5, k = 2e5;
    set<pii> rc;
    rep(i,0,k) {
        rc.insert({rnd(1,n+1),rnd(1,m+1)});
    }
    k = sz(rc);
    cout <<n <<" " <<m <<" " <<k <<"\n";
    for(auto [ri,ci]: rc) {
        cout <<ri <<" " <<ci <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}