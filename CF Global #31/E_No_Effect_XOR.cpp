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

const int mxn=1e5;
int t;
ll l,r;
using lpll = pair<ll,pll>;

void coba(ll le, ll re, ll li, ll ri, vector<lpll>& v) {
    if(re<li || ri<le) {
        ll b = 1+__builtin_ctzll(re-le+1);
        v.push_back({b,{le,re}});
        return;
    }
    if(le>=li && re<=ri) {
        ll b = 1+__builtin_ctzll(re-le+1);
        v.push_back({b,{le,re}});
        return;
    }
    ll mid = (re+le)/2;
    coba(le,mid,li,ri,v);
    coba(mid+1,re,li,ri,v);
}

void gen(ll li, ll ri, vector<lpll>& v) {
    ll bit = 64 - __builtin_clzll(ri);
    coba(0,(1ll<<bit)-1,li,ri, v);
}

void solve() {
    cin >>l >>r;
    vector<lpll> v;
    gen(l,r,v);
    // debug() <<imie(v);
    ll mn = 50;
    vector ps(51,vector<pll>());
    vector<ll> cand;
    for(auto& [b,leri]: v) {
        min_self(mn, b);
        if(leri.fi>=l && leri.se<=r) {
            ps[b].push_back(leri);
            cand.push_back(leri.fi);
            cand.push_back(leri.se);
        }
    }
    debug() <<imie(cand);
    set<ll> ms, ms2;
    auto tes = [&](ll xi) -> void {
        for(auto& candi: cand) {
            ll cur = candi^xi;
            if(cur<l || cur>r) {
                return;
            }
        }
        cout <<xi <<endl;
        ms.insert(xi);
    };
    rep(i,0,51) {
        rep(j,0,sz(ps[i])) {
            rep(k,j+1,sz(ps[i])) {
                auto [a,b] = ps[i][j];
                auto [c,d] = ps[i][k];
                ms2.insert(a^c);
                ms2.insert(a^d);
                // ms2.insert(b^c);
                // ms2.insert(b^d);
            }
        }
        rep(j,0,sz(ps[i])) {
            rep(i2,i+1,51) {
                rep(k,0,sz(ps[i2])) {
                    auto [a,b] = ps[i][j];
                    auto [c,d] = ps[i2][k];
                    ms2.insert(a^c);
                    ms2.insert(a^d);
                    ms2.insert(b^c);
                    ms2.insert(b^d);                    
                }
            }
        }
    }
    ll ans = 1;
    for(auto msi: ms2) {
        // cek ctz dulu. ntar kali mn -1
        ll ctz = __builtin_ctzll(msi);
        if(ctz>=(mn-1)) {
            tes(msi);
        }
    }
    ans += 1ll*sz(ms);
    ans *= (1ll<<(mn-1));
    ans--;
    assert(ans>=0);
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