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

const int mxn=1e5,mxa=1e6;
int n;
int a[mxn];
int fp[mxa+1];
const ll mod = 1e9+7;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector pw(mxa+1,vector<pii>());
    map<int,int> mp;
    rep(i,0,n) {
        int u = a[i];
        while(u>1) {
            int v = fp[u], ct = 0;
            while((u%v)==0) {
                u /= v;
                ct++;
            }
            pw[v].push_back({ct,i});
            max_self(mp[v], ct);
        }
    }
    ll ans = 1;
    rep(i,2,mxa+1) {
        if(sz(pw[i])==0) continue;
        int mx = mp[i];
        vector<ll> dp(mx+1,0);
        dp[0] = 1;
        int ls = -1;
        // debug() <<imie(i);
        // debug() <<imie(pw[i]);
        rep(j,0,sz(pw[i])) {
            auto [ct, id] = pw[i][j];
            if(id==0) {
                rep(k,0,ct+1) {
                    dp[k] = 1;
                }
                // ls = id;
                // continue;
            }
            if(id > ls+1) {
                rep(k,1,mx+1) {
                    dp[k] = 0;
                }
            }
            vector<ll> dp_new(mx+1,0);
            ll sm = 0;
            rep(k,0,ct+1) {
                sm = (sm + dp[k])%mod;
                if(k==ct) {
                    dp_new[k] = sm;
                } else {
                    dp_new[k] = dp[ct];
                }
            }
            dp.swap(dp_new);
            ls = id;
        }
        // debug() <<imie(pw[i].back().se) imie(n-1);
        if(pw[i].back().se!=n-1) {
            rep(k,1,mx+1) {
                dp[k] = 0;
            }
        }
        // debug() <<imie(dp);
        ll mul = 0;
        rep(k,0,mx+1) {
            mul = (mul + dp[k])%mod;
        }
        // debug() <<imie(mul);
        ans = ans*mul%mod;
    }
    cout <<ans <<"\n";
}

void init() {
    bitset<mxa+1> iscomp;
    rep(i,2,mxa+1) {
        if(!iscomp[i]) {
            fp[i] = i;
            for(ll j= 1ll*i*i;j<=mxa;j+=i) {
                iscomp[j] = 1;
                if(fp[j]) {
                    min_self(fp[j], i);
                } else {
                    fp[j] = i;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}