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
int n,m;
int l[mxn],r[mxn],a[mxn];

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
FT ft(mxn);

void add(int ind, int end) { 
    ft.update(r[ind]+1,1);
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    ft.update(r[ind]+1,-1);
} // remove a[ind]
int calc(int i) {
    // int tp = (r[i]+1)>=i;
    // return ft.query(n)-ft.query(i)-tp;
    return ft.query(i+1)-1;
} // compute current answer

vi mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
	vi s(sz(Q)), res = s;
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) {
		pii q = Q[qi];
		while (L > q.first) add(--L, 0);
		while (R < q.second) add(R++, 1);
		while (L < q.first) del(L++, 0);
		while (R > q.second) del(--R, 1);
		res[qi] = calc(q.fi);
	}
	return res;
}

void solve() {
    cin >>n >>m;
    vector adj(n,vi());
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
    }
    rep(i,0,n) {
        cin >>a[i]; a[i]--;
    }
    vi idx(n,-1);
    rep(i,0,n) {
        idx[a[i]] = i;
    }
    rep(i,0,n) {
        l[i] = n;
        r[i] = -1;
    }
    rep(i,0,n) {
        for(auto v: adj[i]) {
            int ii = idx[i], iv = idx[v];
            min_self(l[ii], iv);
            max_self(r[iv], ii);
        }
    }
    vector<pii> que;
    rep(i,0,n) {
        que.push_back({i,l[i]});
    }
    // debug() <<imie(que);
    // vector<pii> tes;
    // rep(i,0,n) {
    //     tes.push_back({r[i]+1,i});
    // }
    // debug() <<imie(tes);
    auto ret = mo(que);
    // debug() <<imie(ret);
    ll ans = 0;
    for(auto reti : ret) {
        ans += reti;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}