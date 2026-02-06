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

const int mxn=400;
int n,k,t;
ll p;

void solve() {
    cin >>n >>k >>p;
    vector dp(k+1, vector<ll>(k+1, 0ll));
    rep(i,0,k+1) {
        rep(j,0,i+1) {
            dp[i][j] = 1;
        }
    }
    per(i,n-3,-1) {
        vector dp_new(k+1, vector<ll>(k+1, 0ll));
        rep(j,0,k+1) {
            vector<ll> add(k+1, 0ll);
            rep(l,0,k+1) {
                int cur =max(0, j-l);
                add[cur] = (add[cur] + dp[j][l])%p; 
            }
            ll temp = 0;
            rep(m,0,k+1) {
                temp = (temp + add[m])%p;
                dp_new[m][j] = (dp_new[m][j] + temp)%p;
            }
        }
        dp.swap(dp_new);
    }
    ll ans = 0;
    rep(i,0,k+1) {
        rep(j,0,k+1) {
            if(j>=i) {
                // debug() <<imie(i) <<imie(j) <<imie(dp[i][j]);
                ans = (ans + dp[i][j])%p;
            }
        }
    }
    cout <<ans <<"\n";
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