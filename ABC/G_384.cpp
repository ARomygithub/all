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

const int mxn=1e5;
int n,k;
int a[mxn],b[mxn];

struct FT {
	vector<ll> s;
	FT() {}
    void init(int n) {
        s.resize(n, 0);
    }
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

vi val;
FT ftx,ctx,fty,cty;
ll sm = 0;

void add(int ind, int end) { 
    // debug() <<imie(ind) imie(end);
    if(end==0) {
        ftx.update(a[ind], val[a[ind]]);
        ctx.update(a[ind], 1);
        ll y = cty.query(sz(val));
        ll sy = fty.query(sz(val));
        ll c = cty.query(a[ind]+1);
        ll sc = fty.query(a[ind]+1);
        // debug() <<imie(y) imie(sy) imie(c) imie(sc);
        sm += y*val[a[ind]]+sy - ((y-c)*val[a[ind]] + sc)*2;
    } else {
        fty.update(b[ind], val[b[ind]]);
        cty.update(b[ind], 1);
        ll x = ctx.query(sz(val));
        ll sx = ftx.query(sz(val));
        ll c = ctx.query(b[ind]+1);
        ll sc = ftx.query(b[ind]+1);
        // debug() <<imie(x) imie(sx) imie(c) imie(sc);
        sm += x*val[b[ind]]+sx - ((x-c)*val[b[ind]] +sc)*2;
    }    
    // cout <<"sm " <<sm <<endl;
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    if(end==0) {
        ftx.update(a[ind], -val[a[ind]]);
        ctx.update(a[ind], -1);
        ll y = cty.query(sz(val));
        ll sy = fty.query(sz(val));
        ll c = cty.query(a[ind]+1);
        ll sc = fty.query(a[ind]+1);
        sm -= y*val[a[ind]]+sy - ((y-c)*val[a[ind]] + sc)*2;        
    } else {
        fty.update(b[ind], -val[b[ind]]);
        cty.update(b[ind], -1);
        ll x = ctx.query(sz(val));
        ll sx = ftx.query(sz(val));
        ll c = ctx.query(b[ind]+1);
        ll sc = ftx.query(b[ind]+1);
        sm -= x*val[b[ind]]+sx - ((x-c)*val[b[ind]] +sc)*2;
    }
    // cout <<"sm " <<sm <<endl;
} // remove a[ind]
ll calc() { 
    return sm;
} // compute current answer

vector<ll> mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
	vi s(sz(Q));
    vector<ll> res(sz(Q));
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) {
		pii q = Q[qi];
		while (L > q.first) del(--L, 0);
		while (R < q.second) add(R++, 1);
		while (L < q.first) add(L++, 0);
		while (R > q.second) del(--R, 1);
		res[qi] = calc();
	}
	return res;
}

auto compress_coords(auto& coords) {
    vi original;
    original.reserve(sz(coords));
    ranges::sort(coords);
    int idx = -1, prev = -1e9;
    for(auto& x: coords) {
        if(x!=prev) {
            idx++;
            prev = x;
            original.push_back(x);
        }
        x.get() = idx;
    }
    return original;
}

void solve() {
    cin >>n;
    vector<reference_wrapper<int>> coords;
    rep(i,0,n) {
        cin >>a[i];
        coords.push_back(ref(a[i]));
    }
    rep(i,0,n) {
        cin >>b[i];
        coords.push_back(ref(b[i]));
    }
    val = compress_coords(coords);
    ftx.init(sz(val));
    fty.init(sz(val));
    ctx.init(sz(val));
    cty.init(sz(val));
    cin >>k;
    vector<pii> qry(k);
    rep(i,0,k) {
        cin >>qry[i].fi >>qry[i].se;
    }
    auto ans = mo(qry);
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}