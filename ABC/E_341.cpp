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
typedef pair<bool,bool> pbb;

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
	int lo, hi, mset = inf, madd = 0;
    bool ok=1, val=0, mflip=0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val;
            bool temp = 0;
            if(((mid-lo)%2)) {
                temp = l->val != r->val;
            } else {
                temp = l->val == r->val;
            }
            ok = l->ok && r->ok && temp;
		}
		else {
            val = v[lo];
        }
	}
	pbb query(int L, int R) {
		if (R <= lo || hi <= L) return {1,0};
		if (L <= lo && hi <= R) return {ok,val};
		push();
        int valL = -1, valR=-1;
        pbb ret = {1,0};
        if(L < l->hi) {
            pbb retL = l->query(L,R);
            valL = retL.se;
            ret.fi &= retL.fi;
        }
        if(R > r->lo) {
            pbb retR = r->query(L,R);
            valR = retR.se;
            ret.fi &= retR.fi;
        }
        if(ret.fi) {
            if(valL!=-1 && valR!=-1) {
                ret.se = valL;
                int lenL = l->hi - max(l->lo,L);
                if(lenL%2) {
                    ret.fi &= valL != valR;
                } else {
                    ret.fi &= valL == valR;
                }
                // debug() <<imie(lo) <<imie(hi);
                // debug() <<imie(ret);
                // debug() <<imie(lenL) <<imie(valL) <<imie(valR);
            } else if(valL!=-1) {
                ret.se = valL;
            } else if(valR!=-1) {
                ret.se = valR;
            }
        }
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
        if(R <= lo || hi <= L) return;
        if(L <= lo && hi <= R) {
            mflip = !mflip;
            val = !val;
        } else {
            push(), l->flip(L,R), r->flip(L,R);
			val = l->val;
            bool temp = 0;
            if(((l->hi-lo)%2)) {
                temp = l->val != r->val;
            } else {
                temp = l->val == r->val;
            }
            ok = l->ok && r->ok && temp;            
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
        else if(mflip) {
            l->flip(lo,hi), r->flip(lo,hi), mflip=0;
        }
	}
    // void dbg() {
    //     debug() <<imie(lo) <<imie(hi);
    //     debug() <<imie(ok) <<imie(val) <<imie(mflip);
    //     if(l) l->dbg();
    //     if(r) r->dbg();
    // }
};

void solve() {
    cin >>n >>q;
    cin >>s;
    vector<int> v(n);
    rep(i,0,n) {
        v[i] = s[i]-'0';
    }
    Node st(v,0,n);
    while(q--) {
        int qt; cin >>qt;
        int l,r;cin >>l >>r; l--;
        if(qt==1) {
            st.flip(l,r);
        } else {
            pbb ret = st.query(l,r);
            if(ret.fi) {
                cout <<"Yes\n";
            } else {
                cout <<"No\n";
            }
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