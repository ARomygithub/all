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

const int mxn=1e6;
const ll mod = 998244353;
int n,t;
int a[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector dp(n+1, vector<ll>(2,0));
    dp[0][1] = 1;
    map<int,ll> mp;
    mp[0] = mod-1;
    int xr = 0;
    vector<ll> sm(2,0);
    sm[0] = 1;
    sm[1] = mod-1;
    ll sm1 = 1;
    rep(i,1,n+1) {
        xr ^= a[i];
        dp[i][0] = (sm1 + mp[xr])%mod;
        if(a[i]!=1) {
            sm[0] = 0;
            sm[1] = 0;
        }
        dp[i][1] = (dp[i][0] + sm[i%2])%mod;
        if(i%2) {
            sm[0] = (sm[0] + dp[i][0] - dp[i][1]+mod)%mod;
            sm[1] = (sm[1] + dp[i][1] - dp[i][0]+mod)%mod;
        } else {
            sm[0] = (sm[0] + dp[i][1] - dp[i][0]+mod)%mod;
            sm[1] = (sm[1] + dp[i][0] - dp[i][1]+mod)%mod;            
        }
        sm1 = (sm1 + dp[i][1])%mod;
        mp[xr] = (mp[xr] + dp[i][0]-dp[i][1]+mod)%mod;
    }
    // debug() <<imie(dp);
    cout <<dp[n][0] <<"\n";
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