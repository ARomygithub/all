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

const int mxn=1e5,lim=100;
const ll mod = 998244353;
int n,t;
map<pii,ll> mp;
vi cand[lim+1];

ll getdp(int ats, int cur) {
    if(mp.count({ats,cur})) return mp[{ats,cur}];
    ll ret = 1;
    if(cur<=lim) {
        for(auto i : cand[cur]) {
            if(i>=ats) break;
            int d = __gcd(cur, i);
            if(d!=cur) {
                // debug() <<imie(ats) imie(cur);
                // debug() <<imie(i) imie(d);
                ret = (ret + getdp(i,d)*2%mod)%mod;
            }            
        }
    } else {
        per(i,ats-1,0) {
            int d = __gcd(cur, i);
            if(d!=cur) {
                // debug() <<imie(ats) imie(cur);
                // debug() <<imie(i) imie(d);
                ret = (ret + getdp(i,d)*2%mod)%mod;
            }
        }
    }
    mp[{ats,cur}] = ret;
    return ret;
}

void solve() {
    cin >>n;
    ll ans = 0;
    rep(i,1,n+1) {
        ans = (ans + getdp(i,i))%mod;
    }
    cout <<ans <<"\n";
}

void init() {
    rep(i,1,mxn+1) {
        rep(j,1,lim+1) {
            if((i%j)==0) continue;
            cand[j].push_back(i);
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
    // rep(i,1,101) {
    //     n = i;
    //     cout <<n <<" ";
    //     solve();
    // }
}