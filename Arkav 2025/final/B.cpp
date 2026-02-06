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

const int mxn=1e5;
const ll mod = 1e9+7;
int n,m;

void solve() {
    cin >>n >>m;
    vector dp(n+1, vector<ll>(m+1,0));
    rep(j,0,m+1) {
        dp[0][j] = 1;
    }
    rep(i,1,n+1) {
        rep(j,1,m+1) {
            dp[i][j] = dp[i][j-1];
            rep(k,1,j+1) {
                rep(l,0,i) {
                    ll ad = dp[l][k]*dp[i-1-l][max(0,j-k-1)]%mod;
                    dp[i][j] = (dp[i][j] + ad)%mod;
                }
            }
        }
    }
    rep(i,1,n+1) {
        debug() <<imie(i);
        debug() <<imie(dp[i]);
    }
    // dp[0][0] = 0;
    vector ad(n+1, vector<ll>(m+1,0));
    // rep(i,0,n+1) {
    //     rep(j,1,m+1) {
    //         ad[i][j] = dp[i][j]-dp[i][j-1];
    //     }
    // }
    rep(i,0,n+1) {
        rep(j,0,m+1) {
            ad[i][j] = dp[i][j];
            if(i>0) {
                ad[i][j] = (ad[i][j] - dp[i-1][j] + mod)%mod;
            }
            if(j>0) {
                ad[i][j] = (ad[i][j] - dp[i][j-1] + mod)%mod;
            }
            if(i>0 && j>0) {
                ad[i][j] = (ad[i][j] + dp[i-1][j-1])%mod;
            }
        }
    }
    rep(i,0,n+1) {
        debug() <<imie(i);
        debug() <<imie(ad[i]);
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}