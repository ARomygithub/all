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
int a[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector id(n+1, vi());
    vi id2(n+1,0);
    rep(i,1,n+1) {
        id[a[i]].push_back(i);
        id2[i] = sz(id[a[i]])-1;
    }
    vi dp(n+1,0);
    rep(i,1,n+1) {
        int len = a[i];
        max_self(dp[i],dp[i-1]);
        if(id2[i]-len+1 >=0) {
            max_self(dp[i], dp[id[len][id2[i]-len+1]-1] + len);
        }
    }
    cout <<dp[n] <<"\n";
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