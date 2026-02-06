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
using piii = pair<pii,int>;

const int mxn=2e5;
int n,m,k;
int r[mxn],c[mxn];

struct Tree {
    typedef pii T;
    static constexpr T unit = {0,-1};
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    cin >>n >>m >>k;
    rep(i,0,k) {
        cin >>r[i] >>c[i]; r[i]--;c[i]--;
    }
    vi par(k,-1), vali(k,0);
    set<piii> s;
    rep(i,0,k) {
        s.insert({{c[i]+r[i],c[i]},i});
    }
    Tree st(m);
    int lsu = -1,mx=0;
    for(auto it=s.begin();it!=s.end();) {
        auto it2 = it;
        vector<piii> tmp;
        while(it2!=s.end() && it2->fi.fi == it->fi.fi) {
            tmp.push_back(*it2);
            it2++;
        }
        for(auto [hx, id]: tmp) {
            auto [h,x] = hx;
            auto qry = st.query(0,x+1);
            auto [val,idp] = qry;
            vali[id] = val+1;
            par[id] = idp;
            debug() <<imie(h) imie(x) imie(id);
            debug() <<imie(vali[id]) imie(par[id]);
            if(idp!=-1) {
                assert(r[id]+c[id]>r[idp]+c[idp]);
            }
            if(vali[id]>mx) {
                mx = vali[id]; lsu=id;
            }
        }
        for(auto [hx,id]: tmp) {
            auto [h,x] = hx;
            st.update(x, {vali[id],id});
        }
        it = it2;
    }
    vector<pii> v;
    cout <<vali[lsu] <<"\n";
    v.push_back({n-1,m-1});
    while(lsu!=-1) {
        v.push_back({r[lsu],c[lsu]});
        // cout <<lsu <<" " <<par[lsu] <<"\n";
        lsu = par[lsu];
    }
    v.push_back({0,0});
    string anss = "";
    per(i,sz(v)-1,0) {
        rep(j,v[i].fi+1,v[i-1].fi+1) {
            anss +='D';
        }
        rep(j,v[i].se+1,v[i-1].se+1) {
            anss +='R';
        }
    }
    cout <<anss <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}