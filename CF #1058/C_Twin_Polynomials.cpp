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

const int mxn=4e5;
const ll mod = 1e9+7;
int n,t;
ll dp[mxn+1];

void init() {
    dp[0] = 1;
    dp[1] = 2;
    rep(i,2,mxn+1) {
        dp[i] = (dp[i-1]*2 + dp[i-2]*(i-1)%mod)%mod;
    }
}

void solve() {
    cin >>n;
    vector<int> udh(n+1,0);
    // debug() <<imie(n);
    vi a(n+1);
    rep(i,0,n+1) {
        cin >>a[i];
    }
    rep(i,0,n+1) {
        int ai = a[i];
        // debug() <<imie(ai);
        if(ai!=-1) {
            if(ai>=1 && ai<=n) {
                if(udh[i]) {
                    if(udh[ai]==i) {
                        continue;
                    } else {
                        cout <<"0\n";
                        return;
                    }
                } else {
                    udh[i] = ai;
                    if(udh[ai]!=0 && udh[ai]!=i) {
                        cout <<"0\n";
                        return;
                    }
                    udh[ai] = i;
                }
            } else {
                if(ai==0) {
                    if(udh[i]) {
                        cout <<"0\n";
                        return;
                    }
                    udh[i] = 1e9;
                } else {
                    cout <<"0\n";
                    return;
                }
            }
        }
        // cout <<flush;
    }
    int blm = 0;
    rep(i,1,n+1) {
        blm += (udh[i]==0);
    }
    if(udh[n]) {
        cout <<dp[blm] <<"\n";
    } else {
        ll ans = 0;
        if(blm>=2) {
            ans = (ans  + 1ll*(blm-1)*dp[blm-2]%mod)%mod;
        }
        ans = (ans + dp[blm-1])%mod;
        cout <<ans <<"\n";
    }
    // cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}