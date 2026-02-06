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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
int n,s,m,l;
int dp[mxn+1];

void solve() {
    cin >>n >>s >>m >>l;
    rep(i,1,n+1) {
        int temp = s+(i-6>0?dp[i-6]:0);
        min_self(temp, m+(i-8>0?dp[i-8]:0));
        min_self(temp, l + (i-12>0?dp[i-12]:0));
        dp[i] = temp;
    }
    cout <<dp[n] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}