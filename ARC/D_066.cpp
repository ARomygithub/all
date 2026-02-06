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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod=1e9+7;
ll n;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a,mod-2);
}

ll f(ll a, ll b) {
    a %=mod; b%=mod;
    ll ret = (b-a+1+mod)%mod;
    ret = ret*(a+b)%mod;
    return ret;
}

void solve() {
    cin >>n;
    ll ans = 0;
    int ctbit = 64-__builtin_clzll(n);
    // cout <<ctbit <<"\n";
    vector dp(ctbit, vector(ctbit+1,vector<ll>(2,0)));
    dp[ctbit-1][0][0] = 1ll;
    dp[ctbit-1][1][1] = 2ll;
    per(r,ctbit-1,0) {
        rep(consec,0,ctbit-r+1) {
            rep(i,0,2) {
                debug() <<imie(r) <<imie(consec) <<imie(i);
                debug() <<imie(dp[r][consec][i]);
                // 0
                int rn = r-1;
                int consecn = 0;
                int in = (i>0&&((n>>rn)&1)==1?0:i);
                dp[rn][consecn][in] = (dp[rn][consecn][in] + dp[r][consec][i])%mod;
                // 1
                consecn = consec+1;
                if(!(((n>>rn)&1)==0 && i==1)) {
                    in = (((n>>rn)&1)==1&&i==1? 1: 0);
                    dp[rn][consecn][in] = (dp[rn][consecn][in] + dp[r][consec][i]*(consecn+1)%mod*inv(consec+1)%mod)%mod;
                }
            }
        }
    }
    rep(consec,0,ctbit+1) {
        rep(i,0,2) {
            dp[0][consec][i] = dp[0][consec][i]*inv(consec+1)%mod;
            ans = (ans+ dp[0][consec][i])%mod;
            debug() <<imie(consec) <<imie(i);
            debug() <<imie(dp[0][consec][i]);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}