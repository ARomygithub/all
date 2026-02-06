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
int n,m;
pll ab[mxn];
using plpl = pair<pll,pll>;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

void solve() {
    cin >>n >>m;
    vector<pll> v;
    set<ll> msy;
    rep(i,0,n) {
        cin >>ab[i].fi >>ab[i].se;
        v.push_back({ab[i].fi-ab[i].se,ab[i].fi+ab[i].se});
        msy.insert(v.back().se);
    }
    vector<plpl> bx;
    rep(i,0,m) {
        ll t,d,x,y,r; cin >>t >>d >>x >>y >>r; 
        ll xx = x-y+t, yy = x+y-t;
        bx.push_back({{xx-r,1},{yy-r, yy+r+1}});
        bx.push_back({{xx+r+d*2 + 1,-1}, {yy-r,yy+r+1}});
        msy.insert(yy-r);
        msy.insert(yy+r+1);
    }
    sort(all(v));
    sort(all(bx));
    map<ll,int> mpy;
    int id = 0;
    for(auto yi : msy) {
        mpy[yi] = id; id++;
    }
    int ans = 0;
    FT ft(id);
    int idb = 0;
    // debug() <<imie(v);
    // debug() <<imie(bx);
    rep(i,0,sz(v)) {
        ll x = v[i].fi;
        while(idb<sz(bx) && bx[idb].fi.fi<=x) {
            // debug() <<imie(i) imie(idb);
            auto [y1,y2] = bx[idb].se;
            ll dif = bx[idb].fi.se;
            // debug() <<imie(y1) imie(y2) imie(dif);
            ft.update(mpy[y1], dif);
            ft.update(mpy[y2], -dif);
            // debug() <<imie(mpy[y1]) imie(mpy[y2]);
            idb++;
        }
        // debug() <<imie(mpy[v[i].se]);
        if(ft.query(mpy[v[i].se]+1)==0) {
            ans++;
        }
    }   
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}