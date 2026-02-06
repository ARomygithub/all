#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
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

const int mxn=3e5;
int n,m,q;

const int inf = 0;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = inf, madd = 0, val = -inf;
    ll dist = 0, s=0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
            dist = l->dist + r->dist;
            s = l->s + r->s;
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return s;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            mset = x;
            val = x*(hi-lo);
            s = x*dist;
        }
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
            dist = l->dist + r->dist;
            s = l->s + r->s;
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			dist += x*(hi-lo);
            s += val*x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
            dist = l->dist + r->dist;
            s = l->s + r->s;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
    // void dbg() {
    //     if(l) {
    //         l->dbg();
    //     }
    //     if(r) {
    //         r->dbg();
    //     }
    //     debug() <<imie(lo) <<imie(hi);
    //     debug() <<imie(mset) <<imie(val);
    //     debug() <<imie(madd) <<imie(dist);
    //     debug() <<imie(s);
    // }
};

void solve() {
    cin >>n >>m >>q;
    set<int> s;
    vi v(n,0);
    Node st(v,0,n);
    vi pos(m),val(n);
    rep(i,0,m) {
        int x; cin >>x; x--;
        s.insert(x);
        pos[i] = x;
    }
    rep(i,0,m) {
        cin >>val[pos[i]];
    }
    rep(i,0,n) {
        auto it = s.lower_bound(i);
        st.add(i,i+1,(*it)-i);
        // debug() <<imie(i) <<imie((*it));
        ll temp;
        if((*it)==i) {
            temp = val[*it];
        } else {
            it--;
            temp = val[*it];
        }
        st.set(i,i+1,temp);
        // debug() <<imie(i) <<imie(temp);
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x,vali; cin >>x >>vali; x--;
            // st set
            auto it = s.lower_bound(x);
            st.set(x,(*it),vali);
            ll awal = (*it)-x;
            it--;
            st.add((*it)+1,x+1,awal*-1);
            s.insert(x);
        } else {
            int l,r; cin >>l >>r; l--;
            cout <<st.query(l,r) <<"\n";
        }
    }
    // st.dbg();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}