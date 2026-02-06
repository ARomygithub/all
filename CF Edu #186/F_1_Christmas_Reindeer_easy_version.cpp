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

const int mxn=500;
const ll mod = 998244353;
const int mxa=1e3;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];
ll pr[mxa+1][mxa+1];
int n,q,t;
int c[61];
vector<ll> s(62,0);

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}
ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
    rep(i,0,mxa+1) {
        pr[i][0] = C(i,0);
        rep(j,1,i+1) {
            pr[i][j] = (pr[i][j-1] + C(i,j))%mod;
        }
    }
}


ll slv(vi& cur, int bit) {
    if(bit==0) {
        if(cur[0]==0) return 0;
        return pr[c[0]][cur[0]-1];
    }
    if(cur[bit]==0) return slv(cur,bit-1);
    ll ret = s[bit]*pr[c[bit]][cur[bit]-1];
    ret = (ret + C(c[bit],cur[bit])*slv(cur,bit-1)%mod)%mod;
    // debug() <<imie(bit) imie(ret);
    return ret;
}

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        int ci; cin >>ci;
        c[ci]++;
    }
    vector<ll> p(62,0);
    p[0] = 1;
    rep(i,1,62) {
        p[i] = p[i-1]*(c[i-1]+1)%mod;
    }
    s[0] = 1;
    rep(i,1,62) {
        ll cur = fastexpo(2,c[i-1]);
        s[i] = s[i-1]*cur%mod;
    }
    // debug() <<imie(s);
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int ci; cin >>ci;
            c[ci]++;
            rep(i,ci+1,62) {
                p[i] = p[i-1]*(c[i-1]+1)%mod;
            }
            rep(i,ci+1,62) {
                ll cur = fastexpo(2,c[i-1]);
                s[i] = s[i-1]*cur%mod;
            }
        } else if(qt==2) {
            int ci; cin >>ci;
            c[ci]--;
            rep(i,ci+1,62) {
                p[i] = p[i-1]*(c[i-1]+1)%mod;
            }
            rep(i,ci+1,62) {
                ll cur = fastexpo(2,c[i-1]);
                s[i] = s[i-1]*cur%mod;
            }            
        } else {
            ll x; cin >>x;
            int ct = 0;
            ll bs = 0;
            vi cur(61,0);
            per(bit,59,-1) {
                if((x>>bit)&1) {
                    cur[bit+ct]++;
                    ct++;
                }
            }
            // debug() <<imie(cur);
            bs = slv(cur,59);
            ll ans = (s[61] - bs + mod)%mod;
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    init_fac();
    while(t--) {
        solve();
    }
}