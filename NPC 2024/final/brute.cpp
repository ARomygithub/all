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

const int mxn=1e3;
int n,m,k,mc;
// n,m 1e3
// max_cap 5e4
// k 200
// c 1000
// t_i 200
vector<pii> adj[mxn];
int t[mxn];
using plli = pair<pll,int>;
using piii = pair<pii,int>;

void solve() {
    cin >>n >>m >>k >>mc;
    // assert(n<=1000);
    // assert(m<=1000);
    // assert(mc<=50000);
    rep(i,0,m) {
        int u,v,c; cin >>u >>v >>c; u--,v--;
        int p = abs(u-v);
        // assert(c<=1000);
        if(c<5) {
            p += c*2;       
        } else if(c<10) {
            p += c*3;
        } else {
            p += c*5;
        }
        adj[u].push_back({p,v});
        adj[v].push_back({p,u});
    }
    rep(i,0,n-1) {
        cin >>t[i];
        // assert(t[i]<=200);
    }
    vector dp(mc+1, vi(n, -1));
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    dp[0][0] = k;
    pq.push({{0,0},-k});
    while(sz(pq)) {
        auto [mcii,dpi] = pq.top(); pq.pop();
        auto [mci, i] = mcii;
        dpi *= -1;
        if(dp[mci][i]>dpi) continue;
        if(i==n-1) continue;
        // debug() <<imie(mci) imie(i) imie(dpi);
        // refill
        if(mci+t[i]<=mc && dp[mci+t[i]][i] < dpi+1) {
            dp[mci+t[i]][i] = dpi+1;
            pq.push({{mci+t[i],i},-dp[mci+t[i]][i]}); 
        }
        for(auto [p,v]: adj[i]) {
            if(dpi>p) {
                if(dp[mci][v]< dpi-p) {
                    dp[mci][v] = dpi-p;
                    pq.push({{mci,v},-dp[mci][v]});
                }
            }
        }
    }
    rep(i,0,mc+1) {
        if(dp[i][n-1]>=0) {
            cout <<i <<"\n";
            return;
        }
    }
    // assert(false);
    cout <<"muak gweh, butuh heal lagi";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}