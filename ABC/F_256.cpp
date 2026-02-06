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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int inf = 0;
const ll mod = 998244353;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll val = 0,mall=0,marit=0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		ll ret = l->query(L, R) + r->query(L, R);
        return (ret%mod);
	}
	void add(int L, int R, ll opArit, ll opAll) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			mall = (mall+opAll)%mod;
            marit = (marit + opArit)%mod;
			val = (val + opAll*(hi-lo)%mod)%mod;
            ll mul = (1ll*(hi-lo)*(hi-lo+1)/2)%mod;
            // assert(mul>=0);
            val = (val + opArit*mul%mod)%mod;
		}
		else {
			push();
            if(L < l->hi) {
                l->add(L, min(R,l->hi), opArit, opAll);
            }
            if(R > r->lo) {
                int le = max(L,r->lo);
                if(L<le) {
                    opAll = (opAll + opArit*(le-L)%mod)%mod;
                }
                r->add(le, R, opArit, opAll);
            }
			val = (l->val + r->val)%mod;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mall!=0 || marit!=0) {
            l->add(l->lo,l->hi,marit,mall);
            ll rmall = marit*(r->lo-lo)%mod;
            rmall = (rmall + mall)%mod;
            r->add(r->lo,r->hi,marit,rmall);
            mall = 0;
            marit = 0;
        }
	}
};

const int mxn=2e5;
int n,q;
int a[mxn];

void solve() {
    cin >>n >>q;
    Node st(0,n);
    rep(i,0,n) {
        cin >>a[i];
        st.add(i,n, a[i], 0ll);
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x,v; cin >>x >>v; x--;
            // assert(((v-a[x])%mod + mod)%mod >=0);
            st.add(x, n, ((v-a[x])%mod + mod)%mod, 0ll);
            a[x] = v;
        } else {
            int x; cin >>x; x--;
            // cout <<st.query(0,1) <<"\n";
            // cout <<st.query(0,2) <<"\n";
            cout <<st.query(0,x+1) <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}