#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
struct TreeMx {
	typedef pii T;
	static constexpr T unit = {INT_MIN,INT_MIN};
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMx(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

struct TreeMn {
	typedef pii T;
	static constexpr T unit = {INT_MAX,INT_MAX};
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMn(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

const int mxn=2e5;
int n,q, who[mxn], a[mxn],b[mxn],c[mxn];
int ncomp = 0;
vector<int> st;
bool vis[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i] >>b[i] >>c[i];
    }
    function<void(int)> dfs1;
    function<void(int)> dfs2;
    TreeMx mxab(n), mxbc(n),mxac(n);
    TreeMn mnab(n), mnbc(n), mnac(n);
    rep(i,0,n) {
        mxab.update(a[i]-1,{b[i],i});
        mnab.update(a[i]-1,{b[i],i});
        mxbc.update(b[i]-1,{c[i],i});
        mnbc.update(b[i]-1,{c[i],i});
        mxac.update(a[i]-1,{c[i],i});
        mnac.update(a[i]-1,{c[i],i});
    }
    dfs1 = [&](int u) -> void {
        if(vis[u]) return;
        vis[u] = 1;
        // nxt blm visit
        pii qryab = mxab.query(a[u]-1,n);
        while(qryab.fi>b[u]) {
            mxab.update(a[qryab.se]-1, {0,0});
            // debug() <<imie(qryab.se);
            dfs1(qryab.se);
            qryab = mxab.query(a[u]-1,n);
        }
        pii qrybc = mxbc.query(b[u]-1,n);
        while(qrybc.fi>c[u]) {
            mxbc.update(b[qrybc.se]-1, {0,0});
            // debug() <<imie(qrybc.se);
            dfs1(qrybc.se);
            qrybc = mxbc.query(b[u]-1,n);
        }
        pii qryac = mxac.query(a[u]-1,n);
        while(qryac.fi>c[u]) {
            mxac.update(a[qryac.se]-1, {0,0});
            dfs1(qryac.se);
            qryac = mxac.query(a[u]-1,n);
            // debug() <<imie(qryac);
            // debug() <<imie(a[u]) <<imie(c[u]);
        }
        st.push_back(u);
    };
    dfs2 = [&](int u) -> void {
        if(!vis[u]) return;
        vis[u] = 0;
        who[u] = ncomp;
        // cout <<u <<"\n" <<flush;
        // nxt udh visit
        pii qryab = mnab.query(0,a[u]-1);
        while(qryab.fi<b[u]) {
            mnab.update(a[qryab.se] - 1, {1e9,1e9});
            dfs2(qryab.se);
            qryab = mnab.query(0,a[u]-1);
        }
        pii qrybc = mnbc.query(0,b[u]-1);
        while(qrybc.fi<c[u]) {
            mnbc.update(b[qrybc.se]-1, {1e9, 1e9});
            dfs2(qrybc.se);
            qrybc = mnbc.query(0,b[u]-1);
        }
        pii qryac = mnac.query(0,a[u]-1);
        while(qryac.fi<c[u]) {
            mnac.update(a[qryac.se]-1, {1e9,1e9});
            dfs2(qryac.se);
            qryac = mnac.query(0,a[u]-1);
        }
    };
    rep(i,0,n) {
        if(!vis[i]) {
            dfs1(i);
        }
    }
    per(i,n-1,-1) {
        int cur = st[i];
        // cout <<"cur " <<cur <<"\n" <<flush; 
        if(vis[st[i]]) {
            dfs2(cur);
            ncomp++;
        }
    }
    cin >>q;
    while(q--) {
        int u,v; cin >>u >>v; u--,v--;
        if(who[u]<=who[v]) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}