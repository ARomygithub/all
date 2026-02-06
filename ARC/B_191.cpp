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
int n,k,t;

void solve() {
    cin >>n >>k;
    vi v;
    rep(i,0,30) {
        if((1<<i) > n) break;
        if(!((n>>i)&1)) {
            v.push_back(i);
        }
    }
    int ct = 1<<(sz(v));
    if(ct<k) {
        cout <<"-1\n";
        return;
    }
    int ans = n;
    k--;
    rep(i,0,sz(v)) {
        if((k>>i)&1) {
            ans += (1<<v[i]);
        }
    }
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