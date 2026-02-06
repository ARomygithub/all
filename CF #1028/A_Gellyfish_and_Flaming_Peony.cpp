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

const int mxn=5e3;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int d = 0;
    vi dp(mxn+1,n+1);
    rep(i,0,n) {
        d = __gcd(d,a[i]);
        dp[a[i]] = 1;
    }
    per(i,mxn,d) {
        if(dp[i]>n) continue;
        rep(j,i+1,mxn+1) {
            if(dp[j]>n) continue;
            int dij = __gcd(i,j);
            min_self(dp[dij], dp[i]+dp[j]);
        }
    }
    int ans = 0;
    rep(i,0,n) {
        ans += (a[i]!=d);
    }
    min_self(ans, n-1);
    ans += (dp[d]-1);
    cout <<ans <<"\n";
}

// void init() {
//     bitset<mxn+1> iscomp;
//     rep(i,2,mxn+1) {
//         if(!iscomp[i]) {
//             pr.push_back(i);
//             for(int j=i*i;j<=mxn;j+=i) {
//                 iscomp[j] = 1;
//             }
//         }
//     }
//     cout <<sz(pr) <<endl;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    // init();
    while(t--) {
        solve();
    }
}