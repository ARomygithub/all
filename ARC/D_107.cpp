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

const int mxn=3e3;
const ll mod=998244353;
int n,k;
vector<vector<ll>> dp;
vector<vector<bool>> flag;

ll get_ans(int ni, int ki) {
    if(ni==ki) {
        return 1;
    }
    if(ni<ki) {
        return 0;
    }
    if(ki==0) {
        return 0;
    }
    if(flag[ni][ki]) return dp[ni][ki];
    // cout <<ni <<" " <<ki <<endl;
    flag[ni][ki] = 1;
    int p2 = 1;
    ll temp = 0ll;
    while(p2<=ni/ki) {
        temp = (temp + get_ans(ni-1,p2*ki-1))%mod;
        p2 *=2;
    }
    dp[ni][ki] = temp;
    // cout <<dp[ni][ki] <<endl;
    return dp[ni][ki];
}

void solve() {
    cin >>n >>k;
    dp.resize(n+1, vector<ll>(n+1,0ll));
    flag.resize(n+1, vector<bool>(n+1,0));
    cout <<get_ans(n,k) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}