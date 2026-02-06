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
typedef pair<int,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e5;
int n,q;
string s;

const int inf = 0;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
    bool mflip=0;
    int pre=0,suf=0;
    int val0=1, pre0=1, suf0=1;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val,r->val);
            max_self(val, l->suf+r->pre);
            val0 = max(l->val0,r->val0);
            max_self(val0, l->suf0+r->pre0);
            pre = l->pre==(l->hi-l->lo)?l->pre+r->pre:l->pre;
            suf = r->suf==(r->hi-r->lo)?l->suf+r->suf:r->suf;
            pre0 = l->pre0==(l->hi-l->lo)?l->pre0+r->pre0:l->pre0;
            suf0 = r->suf0==(r->hi-r->lo)?l->suf0+r->suf0:r->suf0;      
		}
		else {
            val = v[lo];
            val0 = 1-v[lo];
            pre = val;
            suf = val;
            pre0 = val0;
            suf0 = val0;
        }
	}
	pipi query(int L, int R) {
		if (R <= lo || hi <= L) return {0,{0,0}};
		if (L <= lo && hi <= R) {
            return {val, {pre,suf}};
        }
		push();
        pipi ql = l->query(L,R);
        pipi qr = r->query(L,R);
        pipi ret;
        ret.se.fi = ql.se.fi==(l->hi-l->lo)?ql.se.fi+qr.se.fi:ql.se.fi;
        ret.se.se = qr.se.se==(r->hi-r->lo)?ql.se.se+qr.se.se:qr.se.se;
        // debug() <<imie((r->hi-r->lo));
        // debug() <<imie(ql.se.se+qr.se.se);
        if(L<l->hi) {
            max_self(ret.fi, ql.fi);
        }
        if(R>r->lo) {
            max_self(ret.fi, qr.fi);
        }
        int temp = 0;
        if(l->hi -1 >=L && l->hi -1 <R) {
            temp += min(l->hi - L, ql.se.se);
        }
        if(r->lo>=L && r->lo<R) {
            temp += min(R-r->lo, qr.se.fi);
        }
        max_self(ret.fi, temp);
        // debug() <<imie(ql);
        // debug() <<imie(qr);
        // debug() <<imie(lo) <<imie(hi) <<imie(mflip);
        // debug() <<imie(ret);
        return ret;
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void flip(int L, int R) {
        if(R<=lo || hi<=L) return;
        if(L<= lo && hi<=R) {
            mflip = !mflip;
            swap(val,val0);
            swap(pre,pre0);
            swap(suf,suf0);
        } else {
            push(), l->flip(L, R), r->flip(L, R);
            val = max(l->val,r->val);
            max_self(val, l->suf+r->pre);
            val0 = max(l->val0,r->val0);
            max_self(val0, l->suf0+r->pre0);
            pre = l->pre==(l->hi-l->lo)?l->pre+r->pre:l->pre;
            suf = r->suf==(r->hi-r->lo)?l->suf+r->suf:r->suf;
            pre0 = l->pre0==(l->hi-l->lo)?l->pre0+r->pre0:l->pre0;
            suf0 = r->suf0==(r->hi-r->lo)?l->suf0+r->suf0:r->suf0;            
        }
    }
    void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        if(mflip) {
            l->flip(lo, hi), r->flip(lo, hi), mflip = 0;
        }
	}
    // void dbg() {
    //     debug() <<imie(val) <<imie(pre) <<imie(suf) <<imie(val0) <<imie(pre0) <<imie(suf0);
    //     debug() <<imie(lo) <<imie(hi) <<imie(mflip);
    //     if(l) {
    //         l->dbg();
    //     }
    //     if(r) {
    //         r->dbg();
    //     }
    // }
};

void solve() {
    cin >>n >>q;
    cin >>s;
    vector<int> v;
    rep(i,0,n) {
        int ai = (s[i]-'0');
        v.push_back(ai);
    }
    Node st(v, 0, n);
    while(q--) {
        int qt; cin >>qt;
        int l,r;
        if(qt==1) {
            cin >>l >>r; l--,r--;
            st.flip(l,r+1);
            // st.dbg();
        } else {
            cin >>l >>r; l--,r--;
            cout <<st.query(l,r+1).fi <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}