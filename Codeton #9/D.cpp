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
int n,m,t;
int b[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        cin >>b[i];
    }
    vi ans(n,-1);
    vector lrg(n, set<int>());
    rep(i,0,n) {
        int x = m-1;
        while(lrg[i].count(x)) {
            x--;
        }
        if(x<0) {
            cout <<"-1\n";
            return;
        }
        ans[i] = b[x];
        for(int j=(i+1)*2;j<=n;j+=(i+1)) {
            lrg[j-1].insert(x);
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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