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
int n,k,t;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
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
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve() {
    cin >>n >>k;
    if(k+1 > n) {
        rep(i,0,n) {
            int a; cin >>a; cout <<"0\n";
        }
        return;
    }
    vi id(n+k+1,0);
    rep(i,k+1,k+n+1) {
        int ans = 0;
        per(j,18,-1) {
            int b1 = (i>>j)&1;
            int b2 = (k>>j)&1;
            if(b1 && (!b2)) {
                ans += (1<<j);
            } else if((!b1) && b2) {
                break;
            }
        }
        id[i] = ans; // bisa >n?
    }
    // debug() <<imie(id);
    Node st(0,n+1);
    rep(i,0,sz(id)) {
        if(id[i]<=n) {
            st.add(id[i], id[i]+1, 1);
        }
    }
    vector<bool> udh(sz(id),0);
    rep(i,0,n) {
        int si; cin >>si;
        if(si<sz(id)) {
            if(udh[si]) {
                udh[si] = 0;
                st.add(id[si], id[si]+1,1);
            } else {
                udh[si] = 1;
                st.add(id[si], id[si]+1,-1);
            }
        }
        int l = 0, r = n;
        int ans = 0;
        // debug() <<imie(udh);
        while(l<=r) {
            int mid = (l+r)/2;
            int qry = st.query(0,mid+1);
            if(qry==0) {
                ans = mid+1;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}