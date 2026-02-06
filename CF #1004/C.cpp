#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
const ll mod = 1e9+7;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector dp(n+1, vector<ll>(2,1));
    // dp[n][0] = 3;
    map<int,int> mp;
    vi xr(n,0);
    rep(i,0,n) {
        xr[i] ^= a[i];
        if(i) {
            xr[i] ^= xr[i-1];
        }
    }
    // debug() <<imie(xr);
    per(i,n-1,-1) {
        mp[xr[i]] = i;
        // if(i==n-1) {
        //     dp[i][0] = 3;
        //     if(a[i-1]==) {
        //         dp[i][1] = 3;
        //     } else {
        //         dp[i][1] = 1;
        //     }
        // } else {
            ll cur0 = (i==0?0: xr[i-1]);
            if(mp.count(cur0)) {
                int id = mp[cur0];
                // debug() <<imie(cur0) imie(i) imie(id);
                dp[i][0] = (dp[id+1][0]%mod + dp[id+1][1]*2%mod)%mod *3%mod;
            } else {
                dp[i][0] = 3;
            }
            ll cur1 = (i==0?0:xr[i-1]^a[i-1]);
            if(mp.count(cur1)) {
                int id = mp[cur1];
                // debug() <<imie(cur1) imie(i) imie(id);
                dp[i][1] = (dp[id+1][0]%mod + dp[id+1][1]*2%mod)%mod;
            }
        // }
    }
    // debug() <<imie(dp);
    cout <<dp[0][0] <<"\n";
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