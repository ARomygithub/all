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

const int mxn=1e5;
ll a,b;
vector<int> prime;

void solve() {
    cin >>a >>b;
    ll len = b-a+1;
    vector<ll> dp((1<<sz(prime)),0);
    dp[0] = 1;
    rep(i,0,len) {
        int statei = 0;
        rep(j,0,sz(prime)) {
            if(((a+i)%prime[j])==0) {
                statei += 1<<j;
            }
        }
        per(bit,(1<<sz(prime))-1,-1) {
            if(!(bit&statei)) {
                dp[bit+statei] += dp[bit];
            }
        }
    }
    ll ans = 0;
    rep(bit,0,(1<<sz(prime))) {
        ans += dp[bit];
    }
    cout <<ans <<"\n";
}

void init() {
    vector<bool> comp(73,0);
    // comp[0] = 1, comp[1] = 1;
    rep(i,2,73) {
        if(!comp[i]) {
            prime.push_back(i);
            for(int j=i+i;j<=72;j+=i) {
                comp[j] = 1;
            }
        }
    }
    // cout <<sz(prime) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}