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
const ll mod=998244353;
int n,t;
int a[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a, ll md = mod) {
    return fastexpo(a, md-2, md);
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll n2 = 1ll*n*(n-1)/2;
    n2 %= mod;
    int k = 0;
    rep(i,0,n) {
        k += (a[i]==1);
    }
    vector<ll> c(k+1);
    int x = 0;
    rep(i,n-k,n) {
        x += (a[i]==1);
    }
    if(x==k) {
        cout <<"0\n";
        return;
    }
    int bw = k - min(n-k,k);
    c[bw+1] = n2*inv(fastexpo(min(n-k,k),2))%mod;
    rep(i,bw+2,k+1) {
        int ai = i-1;
        c[i] = (c[i-1]*(n-k*2+ai)%mod*ai%mod + n2)%mod;
        c[i] = c[i]*inv(fastexpo(k-ai,2))%mod;
    }
    debug() <<imie(bw);
    debug() <<imie(k) imie(x) imie(n2);
    debug() <<imie(c);
    ll ans = 0;
    rep(i,x+1,k+1) {
        ans = (ans + c[i])%mod;
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