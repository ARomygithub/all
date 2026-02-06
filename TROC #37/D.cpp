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
const ll mod=998244353;
int n;
int a[mxn*2];

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
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n;
    rep(i,0,n*2) {
        cin >>a[i];
    }
    if(n==1) {
        cout <<(1ll*a[0]*2+a[1])%mod <<"\n";
        return;
    }
    vector<ll> w(n*2,0);
    vector<ll> pipref(n*2,0);
    pipref[0] = (n-1)%mod;
    vector<ll> pi2pref(n*2,1);
    pi2pref[0] = n%mod;
    rep(i,1,n*2) {
        if(i<n) {
            pipref[i] = pipref[i-1]*(n-1)%mod;
            pi2pref[i] = pi2pref[i-1]*n%mod;
        } else {
            pipref[i] = pipref[i-1]*(n*2-i-1)%mod;
            pi2pref[i] = pi2pref[i-1]*(n*2-i)%mod;
        }
    }
    // debug() <<imie(pipref);
    vector<ll> pi2suf(n*2,1);
    per(i,n*2-2,-1) {
        if(i<n) {
            pi2suf[i] = pi2suf[i+1]*(n)%mod;
        } else {
            pi2suf[i] = pi2suf[i+1]*(n*2-i)%mod;
        }
    }
    // debug() <<imie(pi2suf);
    vector<ll> wpref(n*2,0);
    rep(i,0,n*2) {
        ll temp = 1ll*(n*2-i)*(i>0?pipref[i-1]:1ll)%mod;
        if(i+1<n*2) {
            temp = temp*pi2suf[i+1]%mod;
        }
        w[0] = (w[0] + temp)%mod;
        wpref[i] = w[0];
    }
    // debug() <<imie(w[0]);
    // debug() <<imie(wpref);
    rep(i,1,n*2) {
        if(i<n) {
            w[i] = w[i-1];
        } else {
            ll temp = (w[n-1]-wpref[i-n]+mod)%mod;
            temp = (temp+mod)%mod;
            temp = temp*inv(pipref[i-n])%mod;
            temp = temp*pi2pref[i-n]%mod;
            w[i] = temp;
        }
    }
    // debug() <<imie(w);
    ll ans = 0;
    rep(i,0,n*2) {
        ans = (ans + w[i]*a[i]%mod)%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}