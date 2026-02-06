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

const int mxn=4e5,inf=1e9;
const ll mod = 1e9+7;
int n;

void solve() {
    cin >>n;
    set<int> st;
    set<pii> cn;
    bool fix = 0;
    ll ans = 1;
    rep(i,0,n) {
        string s; int p; cin >>s >>p;
        if(s[1]=='D') {
            if(!fix) {
                if(sz(st)>0) {
                    auto it = st.lower_bound(p);
                    if(it==st.begin()) {
                        if(cn.count({-inf,*it})) {
                            cn.insert({p,*it});
                        }
                        cn.erase({-inf,*it});
                        cn.insert({-inf,p});
                    } else if(it==st.end()) {
                        it--;
                        if(cn.count({*it,inf})) {
                            cn.insert({*it,p});
                        }
                        cn.erase({*it,inf});
                        cn.insert({p,inf});
                    } else {
                        auto it2 = it; it2--;
                        if(cn.count({*it2,*it})) {
                            cn.erase({*it2,*it});
                            cn.insert({*it2,p});
                            cn.insert({p,*it});
                        }
                    }
                } else {
                    cn.insert({-inf,p}); // all seller
                    cn.insert({p,inf}); // all buyer
                }
                st.insert(p);
            } else {
                assert(sz(cn)==1);
                auto [l,r] = *cn.begin();
                
                if(p>l && p<r) {
                    cn.clear();
                    fix = 0;
                    cn.insert({l,p});
                    cn.insert({p,r});
                }
                st.insert(p);
            }
        } else {
            if(!fix) {
                auto it = st.upper_bound(p);
                bool ri = 0;
                int ra,la;
                if(it!=st.end()) {
                    ri = cn.count({p,*it});
                    ra = *it;
                } else {
                    ri = cn.count({p,inf});
                    ra = inf;
                }
                auto iti = st.lower_bound(p);
                bool le = 0;
                if(iti != st.begin()) {
                    auto iti2 = iti; iti2--;
                    le = cn.count({*iti2, p});
                    la = *iti2;
                } else {
                    la = -inf;
                    le = cn.count({-inf,p});
                }
                ans = ans*(le+ri)%mod;
                cn.clear();
                fix = 1;
                cn.insert({la,ra});
            } else {
                assert(sz(cn)==1);
                auto [l,r] = *cn.begin();
                if(p!=l && p!=r) {
                    cout <<"0\n";
                    return;
                }
                cn.clear();
                int la,ra;
                auto it = st.upper_bound(p);
                if(it == st.end()) {
                    ra = inf;
                } else {
                    ra = *it;
                }
                auto it2 = it; it2--;
                if(it2 == st.begin()) {
                    la = -inf;
                } else {
                    it2--;
                    la = *it2;
                }
                cn.insert({la,ra});
            }
            if(sz(st)==1) {
                fix = 0;
                // tp = -1;
                cn.clear();
            }
            st.erase(p);
        }
        if(sz(cn)) {
            auto [l,r] = *cn.begin();
            assert(l!=-inf || r!=inf);
        }
        // debug() <<imie(i);
        // debug() <<imie(st);
        // debug() <<imie(cn);
        // debug() <<imie(fix);
        // cout <<ans <<endl;
    }
    // if(sz(st)==1) {
    //     if(tp==-1) {
    //         ans = ans*2ll%mod;
    //     }
    // } else if(sz(st)>1) {
    //     // case all buy, sell
    //     if(!fix) {

    //     }
    if(sz(st)>0) {
        ans = ans*sz(cn)%mod;
    }
    // }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // bool le = 1;
    // bool ri = 1;
    // cout <<le+ri <<endl;
    solve();
}