#include <bits/stdc++.h>
using namespace std;

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
int q,d;
using piii = pair<int,pii>;

const int inf = 0,setc=1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = setc, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R)+ r->query(L, R);
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, madd = 0, val=x*(hi-lo);
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != setc) mset = (mset + x)%2;
			else madd = (madd + x)%2;
			x %= 2;
            if(x) {
                val = (hi-lo)-val;
            }
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val+ r->val;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != setc)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = setc;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve() {
    cin >>d >>q;
    Node st(0,d);
    vector<pii> vlr;
    auto op = [&](int l, int r) -> void {
        int al = ((l+d-1)/d)*d;
        if(l<al) {
            if(r>=al) {
                st.add(l%d, d,1);
            } else {
                st.add(l%d, r%d + 1, 1);
            }
        }
        int br = (r/d)*d;
        if(br>=l) {
            st.add(0,r%d + 1,1);
        }
    };
    rep(i,0,q) {
        int qt; cin >>qt;
        if(qt==1) {
            int l,r; cin >>l >>r; l--,r--;
            vlr.push_back({l,r});
            op(l,r);
        } else {
            int w; cin >>w;
            // que.push_back({qt,{w,0}});
            int nd = __gcd(d,w);
            if(nd!=d) {
                st.set(0,d,0);
                d = nd;
                for(auto [l,r]: vlr) {
                    op(l,r);
                }
            }
        }
        int val = st.query(0,d);
        cout <<min(d-val,val) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}