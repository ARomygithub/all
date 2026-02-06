#include <bits/stdc++.h>

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
    ris << "(" << d.first << ", " <<d.second <<")";
}
sim dor(rge<c> d) {
    *this << "[";
    for(auto it = d.b; it != d.e;++it)
        *this <<", " + 2 * (it==d.b) <<*it;
    ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]"

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = 998244353;
ll fastexpo(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[1001][11];
    for(int i=1; i<=n; i++){
        dp[i][0] = fastexpo(2, i-1);
    }
    for(int i=1; i<=k; i++){
        for(int j=2*i+1; j<=n; j++){
            ll a = (2*(i+1))%mod;
            a = (a * dp[j-1][i]%mod)%mod;
            ll b = (j - (2*i%mod) + mod)%mod;
            b = (b * dp[j-1][i-1]%mod)%mod;
            dp[j][i] = (a + b)%mod;
        }
    }
    cout << dp[n][k] << "\n";

    return 0;
}