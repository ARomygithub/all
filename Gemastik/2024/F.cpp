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

const int mxn=1e3;
int n,p,q;
map<ll,ll> dp;

ll getDp(ll x) {
    if(dp.count(x)) {
        return dp[x];
    }
    ll x2 = x/2;
    ll x3 = x/3;
    if(x2<p && x3*2<q) {
        return x;
    }
    ll temp = 1e18;
    if(x2>=p) {
        ll temp2 = (x%2)+p;
        temp2 += getDp(x2);
        min_self(temp, temp2);
    }
    if(x3*2>=q) {
        ll temp2 = (x%3)+q;
        temp2 += getDp(x3);
        min_self(temp, temp2);
    }
    dp[x] = temp;
    return temp;
}

void solve() {
    cin >>n >>p >>q;
    // n = 1000;
    // p = rng()
    while(n--) {
        ll ai; cin >>ai;
        cout <<getDp(ai) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}