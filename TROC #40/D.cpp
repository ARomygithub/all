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
int n;
int a[mxn+1];

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    FT ft(n+1);
    ll ans = 0;
    rep(i,1,n+1) {
        ans += (i-1) - ft.query(a[i]);
        ft.update(a[i],1);
    } 
    Node st(0,n+1);
    rep(i,1,n+1) {
        st.add(i,n+1,-1);
    }
    vector<pii> v;
    rep(i,1,n+1) {
        v.push_back({a[i],i});
    }
    sort(all(v));
    int mx = 0;
    per(i,sz(v)-1,-1) {
        auto [val,id] = v[i];
        int pr = st.query(id-1,id);
        max_self(mx, pr - st.query(0,id));
        st.add(id,n+1,2);
    }
    cout <<ans-mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}