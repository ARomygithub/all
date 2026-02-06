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
int n,q;

set<pii>::iterator addInterval(set<pii>& is, int L, int R) {
    if (L == R) return is.end();
    auto it = is.lower_bound({L, R}), before = it;
    while (it != is.end() && it->first <= R) {
        R = max(R, it->second);
        before = it = is.erase(it);
    }
    if (it != is.begin() && (--it)->second >= L) {
        L = min(L, it->first);
        R = max(R, it->second);
        is.erase(it);
    }
    return is.insert(before, {L,R});
}

void removeInterval(set<pii>& is, int L, int R) {
    if (L == R) return;
    auto it = addInterval(is, L, R);
    auto r2 = it->second;
    if (it->first == L) is.erase(it);
    else (int&)it->second = L;
    if (R != r2) is.emplace(R, r2);
}

using ipii = pair<int,pii>;

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MIN;
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
    cin >>n >>q;
    vector upd(2, vector<ipii>());
    vector<pii> qry;
    rep(i,0,q) {
        int qt; cin >>qt;
        if(qt==0) {
            int l,r,x; cin >>l >>r >>x; l--;
            upd[x].push_back({i,{l,r}});
        } else {
            int j; cin >>j; j--;
            qry.push_back({i,j});
        }
    }
    set<pii> s;
    s.insert({0,n});
    vi val(n, -1);
    Tree st(n);
    const int inf = 1e9;
    for(auto [id,lr]: upd[0]) {
        auto [l,r] = lr;
        auto it = s.upper_bound({l,inf});
        if(it!=s.begin()) {
            it--;
        }
        while(it!=s.end()) {
            // debug() <<imie(max(it->fi,l)) imie(min(it->se,r));
            rep(i,max(it->fi,l), min(it->se,r)) {
                val[i] = 0;
                st.update(i, id);
            }
            if((it->se)>=r) break;
            it++;
        }
        removeInterval(s, l, r);
    }
    debug() <<imie(s);
    for(auto [id, lr]: upd[1]) {
        auto [l,r] = lr;
        auto it = s.upper_bound({l,inf});
        if(it!=s.begin()) {
            it--;
        }
        int ct = 0;
        int ps = -1;
        debug() <<imie(lr);
        while(it!=s.end()) {
            if(ps==-1 && max(l,it->fi)<r && max(l,it->fi)<it->se) {
                ps = max(l,it->fi);
            }
            int len = min(it->se,r)-max(it->fi,l);
            if(len>0) {
                ct += len;
            }
            if(it->se >= r) break;
            if(ct>1) break;
            it++;
        }
        if(ct==1) {
            val[ps] = 1;
            int tsi = max(id, st.query(l,r));
            debug() <<imie(ps) imie(tsi);
            st.update(ps, tsi);
        }
    }
    // debug() <<imie(val[1183]);
    // rep(i,1183,1184) {
    //     debug() <<imie(i) imie(st.query(i,i+1));
    // }
    for(auto [id,j]: qry) {
        if(val[j]!=-1 && st.query(j,j+1)<id) {
            cout <<(val[j]>0?"YES\n":"NO\n");
        } else {
            cout <<"N/A\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}