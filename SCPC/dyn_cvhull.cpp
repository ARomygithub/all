#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

struct pt {
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

bool ccw(pt p, pt q, pt r) { // counter-clockwise
	return ((q-p)^(r-q)) > 0;
}

struct upper {
	set<pt> se;
	set<pt>::iterator it;

	int is_under(pt p) { // 1 -> inside ; 2 -> border
		it = se.lower_bound(p);
		if (it == se.end()) return 0;
		if (it == se.begin()) return p == *it ? 2 : 0;
		if (ccw(p, *it, *prev(it))) return 1;
		return ccw(p, *prev(it), *it) ? 0 : 2;
	}
	void insert(pt p) {
		if (is_under(p)) return;

		if (it != se.end()) while (next(it) != se.end() and !ccw(*next(it), *it, p))
			it = se.erase(it);
		if (it != se.begin()) while (--it != se.begin() and !ccw(p, *it, *prev(it)))
			it = se.erase(it);

		se.insert(p);
	}
};

struct dyn_hull { // 1 -> inside ; 2 -> border
	upper U, L;

	int is_inside(pt p) {
		int u = U.is_under(p), l = L.is_under({-p.x, -p.y});
		if (!u or !l) return 0;
		return max(u, l);
	}
	void insert(pt p) {
		U.insert(p);
		L.insert({-p.x, -p.y});
	}
	int size() {
		int ans = U.se.size() + L.se.size();
		return ans <= 2 ? ans/2 : ans-2;
	}
};

const int mxn=1e5;
int n;
dyn_hull dh;

void solve() {
    cin >>n;
    dh.insert(pt(0,0));
    map<int,int> ct_a;
    map<int,int> ct_b;
    set<pii> s;
    int mx_a = 0, mx_b = 0;
    while(n--) {
        int qt; cin >>qt;
        if(qt==1) {
            int a,b; cin>>a >>b;
            max_self(mx_a, a);
            max_self(mx_b, b);
            if(s.find({a,b})!=s.end()) continue;
            s.insert({a,b});
            ct_a[a]++;
            ct_b[b]++;
            dh.insert(pt(a,b));
            dh.insert(pt(a,0));
            dh.insert(pt(0,b));
        } else {
            debug() <<imie(dh.size()) << imie(s.size()) <<imie(ct_a[mx_a]) <<imie(ct_b[mx_b]);
            // int ans = dh.size() - (mx_a!=0) - (mx_b!=0) - 1 - ct_a[mx_a] - ct_b[mx_b] + 2*(mx_a!=0 || mx_b!=0 || s.find({0,0})!=s.end());
            int ans = dh.size() - (mx_a!=0) - (mx_b!=0) - 1;
            cout <<ans <<"\n";
            cout <<flush;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}