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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n,q;
string s;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
    bool operator!=(H o) const { return get() != o.get();}
    H operator+=(H o) {
        (*this) = x + o.x + (x + o.x < x);
        return *this;
    }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)
H pw[mxn+1];
typedef pair<H,H> phh;

const phh inf = {H(),H()};
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    phh mset = inf, madd = inf, val = inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	// Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
	// 	if (lo + 1 < hi) {
	// 		int mid = lo + (hi - lo)/2;
	// 		l = new Node(v, lo, mid); r = new Node(v, mid, hi);
	// 		val = max(l->val, r->val);
	// 	}
	// 	else val = v[lo];
	// }
	phh query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
        phh ret1 = l->query(L,R);
        phh ret2 = r->query(L,R);
        phh ret;
        if(L < l->hi) {
            ret.fi = ret1.fi;
        } else {
            ret.fi = H();
        }
        if(R - r->lo > 0) {
            ret.fi = ret.fi * pw[min(R,r->hi) - r->lo] + ret2.fi;
        }
        if(R - r->lo > 0) {
            ret.se = ret2.se;
        } else {
            ret.se = H();
        }
        if(l->hi - L > 0) {
            ret.se = ret.se * pw[l->hi - max(L,l->lo)] + ret1.se;
        }
        // debug() <<imie(max(L,l->lo)) <<imie(min(R,r->hi));
        // debug() <<imie(ret.fi.get()) <<imie(ret.se.get());
		return ret;
	}
	void set(int L, int R, phh x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = inf;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			phh ret1 = l->val;
            phh ret2 = r->val;
            val = {ret1.fi* pw[r->hi - r->lo] + ret2.fi, ret2.se * pw[l->hi - l->lo] + ret1.se};
            // cout <<"lo " <<lo <<"hi " <<hi <<"\n";
            // cout <<val.fi.get()  <<" " <<val.se.get() <<"\n";
            // cout <<ret1.fi.get() <<" " <<ret1.se.get() <<"\n";
            // cout <<ret2.fi.get() <<" " <<ret2.se.get() <<"\n";
		}
	}
	void add(int L, int R, phh x) {
		// if (R <= lo || hi <= L) return;
		// if (L <= lo && hi <= R) {
		// 	if (mset != inf) mset += x;
		// 	else madd += x;
		// 	val += x;
		// }
		// else {
		// 	push(), l->add(L, R, x), r->add(L, R, x);
		// 	val = max(l->val, r->val);
		// }
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd != inf)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = inf;
	}
};

void solve() {
    cin >>n >>q;
    cin >>s;
    Node st(0,n);
    rep(i,0,n) {
        st.set(i,i+1,{H(s[i]),H(s[i])});
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x; char c; cin >>x >>c; x--;
            st.set(x,x+1,{H(c),H(c)});
        } else {
            int l,r; cin >>l >>r; l--;
            phh ret = st.query(l,r);
            // cout <<ret.fi.get() <<" " <<ret.se.get() <<"\n";
            if(ret.fi == ret.se) {
                cout <<"Yes\n";
            } else {
                cout <<"No\n";
            }
        }
    }
}

void init() {
    pw[0] = 1;
    rep(i,1,mxn+1) {
        pw[i] = pw[i-1] * C;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}