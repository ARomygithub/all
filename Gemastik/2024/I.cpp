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

const int mxn=2e5;
int n,q;
int a[mxn];
ll dp[mxn+1];
bool vis[mxn+1];

ll getAns(int x) {
    if(vis[x]) {
        return dp[x];
    }
    vis[x] = 1;
    dp[x] = 0;
    for(int i=n-x;i>=0;i-=x) {
        dp[x] += (a[i]/2);
    }
    return dp[x];
}

void solve() {
    cin >>n >>q;
    ll sm = 0;
    rep(i,0,n) {
        cin >>a[i];
        sm += a[i];
    }
    sort(a,a+n);
    while(q--) {
        int xi; cin >>xi;
        ll qry = getAns(xi);
        cout <<sm-qry <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}