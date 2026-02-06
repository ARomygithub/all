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
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(Node* nn) {
        l = nn->l;
        r = nn->r;
        val = nn->val;
        lo = nn->lo;
        hi = nn->hi;
        madd = nn->madd;
    }
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R)+ r->query(L, R);
	}
	Node* add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return this;
		if (L <= lo && hi <= R) {
			Node* nw = new Node(this);
            nw->madd += x;
			nw->val += x;
            // cout <<nw->val <<"\n";
            return nw;
		}
		else {
			push();
            Node* nw = new Node(this);
            nw->l = l->add(L, R, x);
            nw->r = r->add(L, R, x);
			nw->val = nw->l->val +  nw->r->val;
            // cout <<nw->val <<"\n";
            return nw;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if(madd) {
			l = l->add(lo,hi,madd);
            r = r->add(lo,hi,madd);
            madd = 0;
        }
	}
};

typedef pair<int,Node*> pin;
const int mxn=2e5;
int n,m,q;

void solve() {
    cin >>n >>m >>q;
    Node st(0,m);
    vector<pin> v;
    v.push_back({-1,0});
    v[0].se = &st;
    vector<pii> set(n, pii({0,0}));
    rep(i,0,q) {
        int qt; cin >>qt;
        if(qt==1) {
            int l,r,x; cin >>l >>r >>x; l--,r--;
            Node* nw = v.back().se->add(l,r+1,x);
            v.push_back({i,nw});
        } else if(qt==2) {
            int j,x; cin >>j >>x; j--;
            set[j] = {i,x};
        } else {
            int j,k; cin >>j >>k; j--,k--;
            auto [id,x] = set[j];
            auto it = lower_bound(v.begin(),v.end(),pin({id,0}));
            ll ans = 0;
            // cout <<(it-v.begin()) <<endl;
            if(it!=v.end()) {
                ans += v.back().se->query(k,k+1);
                if(it!=v.begin()) {
                    it--;
                    ans -= it->se->query(k,k+1);
                }
            }
            ans += x;
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}