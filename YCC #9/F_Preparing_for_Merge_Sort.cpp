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
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    // big to small
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<vi> va;
    vi v;
    rep(i,0,n) {
        auto it = upper_bound(all(v), -a[i]);
        if(it==v.end()) {
            v.push_back(-a[i]);
            va.push_back(vi());
            va.back().push_back(a[i]);
        } else {
            int id = it-v.begin();
            va[id].push_back(a[i]);
            *it = -a[i];
        }
    }
    rep(i,0,sz(va)) {
        rep(j,0,sz(va[i])) {
            cout <<va[i][j] <<" \n"[j==sz(va[i])-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}