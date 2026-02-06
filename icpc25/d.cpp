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

const int mxn=300;
const ll mod = 998244353;
int n;
int a[mxn];

ll fastexpo(ll ai, ll bi) {
    ll ret = 1;
    while(bi) {
        if(bi&1) ret = ret*ai%mod;
        ai = ai*ai%mod;
        bi >>= 1;
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector pr3(n, vector<ll>(n,0));
    vector dp(n, vector<ll>(n+1,0));
    rep(i,0,n) {
        dp[i][n] = 1;
    }   
    per(i,n-2,-1) {
        per(j,n-1,i) {
            ll mul = fastexpo(2,j-i-1);
            
        }
    }
    cout <<dp[0][1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}