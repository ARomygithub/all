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

const int mxn=1e6;
int t;
ll n;
map<int,pll> mp;
int fp[mxn+1];
vi pr;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll fastexpo(ll x, ll e, ll md) {
    ll ret = 1;
    while(e) {
        if(e&1) {
            __int128_t retx = (__int128_t)(ret)*x%md;
            ret = retx;
        }
        __int128_t xx = (__int128_t)(x)*x%md;
        x = xx;
        e >>=1;
    }
    return ret;
}

void solve() {
    cin >>n;
    if(mp.count(n)) {
        auto [a,m] = mp[n];
        cout <<a <<" " <<m <<"\n";
        return;
    }
    vi pri;
    set<int> sp;
    auto getpr = [&](ll x) -> void {
        int id = 0;
        while(x>mxn) {
            if(1ll*pr[id]*pr[id] > x) break;
            if((x%pr[id])==0) {
                if(!sp.count(pr[id])) {
                    pri.push_back(pr[id]);
                    sp.insert(pr[id]);
                }
                while((x%pr[id])==0) {
                    x /= pr[id];
                }
            }
            id++;
        }
        if(x>mxn) {
            if(!sp.count(x)) {
                pri.push_back(x);
                sp.insert(x);
            }
        } else {
            while(x>1) {
                int cur = fp[x];
                if(!sp.count(cur)) {
                    pri.push_back(cur);
                    sp.insert(cur);
                }
                while((x%cur)==0) {
                    x /= cur;
                }
            }
        }
    };
    getpr(n);
    ll m = n*n;
    ll ord0 = 1;
    // debug() <<imie(pri);
    rep(i,0,sz(pri)) {
        ord0 = ord0*(pri[i]-1);
        // m *= pri[i];
    }
    ll mul = m;
    rep(i,0,sz(pri)) {
        mul /= pri[i];
    }
    getpr(ord0);
    ord0 *= mul;
    // ord0 *= n;
    auto getord = [&](ll x) -> ll {
        ll ord1 = ord0;
        rep(i,0,sz(pri)) {
            while((ord1%pri[i])==0) {
                ll ordn = ord1/pri[i];
                if(fastexpo(x,ordn,m)==1) {
                    ord1 = ordn;
                } else {
                    break;
                }
            }
        }
        return ord1;
    };
    ll a = 2;
    ll orda = getord(a);
    // rep(i,2,m) {
    //     if(__gcd(1ll*i,m)!=1) continue;
    //     orda = getord(i);
    //     a = i;
    //     debug() <<imie(a) imie(orda);
    //     if((orda%n)==0) break;
    // }
    while(__gcd(a,m)!=1 ||  (orda%n) !=0) {
        a = rng()%m;
        if(__gcd(a,m)!=1) continue;
        orda = getord(a);
    }
    // debug() <<imie(a) imie(orda) imie(m);
    a = fastexpo(a,orda/n,m);
    if(a<=0) {
        a += m;
    }
    cout <<a <<" " <<m <<"\n";
    mp[n] = {a,m};
}

void init() {
    vector<bool> iscomp(mxn+1,0);
    rep(i,2,mxn+1) {
        if(!iscomp[i]) {
            pr.push_back(i);
            fp[i] = i;
            for(ll j=1ll*i*i;j<=mxn;j+=i) {
                iscomp[j] = 1;
                if(fp[j]==0) {
                    fp[j] = i;
                } else {
                    min_self(fp[j], i);
                }
            }
        }
    }
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