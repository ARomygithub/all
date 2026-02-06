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

const int mxn=1e9,mxk=9,mxb=1e3;
const ll mod = 1e9+7;
ll n;
int b,k, c[mxk];

void solve() {
    cin >>n >>b >>k;
    rep(i,0,k) {
        cin >>c[i];
    }
    vector pw10(61,0ll);
    pw10[0] = 10%b;
    rep(j,1,61) {
        pw10[j] = pw10[j-1]*pw10[j-1]%b;
    }
    vector dp(60, vector<ll>(b,0));
    rep(i,0,k) {
        int cur = c[i]%b;
        dp[0][cur] = (dp[0][cur] + 1)%mod;
    }
    rep(j,1,60) {
        rep(i1,0,b) {
            ll x = 1ll*i1*pw10[j-1]%b;
            // if(j==1) {
            //     debug() <<imie(i1) imie(x);
            // }
            rep(i2,0,b) {
                ll cur = dp[j-1][i1]*dp[j-1][i2]%mod;
                // if(j==1 && dp[j-1][x] && dp[j-1][i2]) {
                //     debug() <<imie(x) imie(i2);
                //     debug() <<imie((x+i2)%b);
                // }
                dp[j][(x+i2)%b] = (dp[j][(x+i2)%b] + cur)%mod; 
            }
        }
    }
    vector<ll> ans(b,0);
    ans[0] = 1;
    rep(j,0,60) {
        if((n>>j)&1) {
            vector<ll> ans_new(b,0);
            rep(i1,0,b) {
                ll x = 1ll*i1*pw10[j]%b;
                rep(i2,0,b) {
                    ll cur = ans[i1]*dp[j][i2]%mod;
                    ll nx = (x+i2)%b;
                    ans_new[nx] = (ans_new[nx] + cur)%mod;
                }
            }
            ans.swap(ans_new);
        }
    }
    // debug() <<imie(dp[1]);
    // debug() <<imie(ans);
    cout <<ans[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}