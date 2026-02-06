#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) ((int) (v).size())
#define FOR(i, begin, end) for(int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for(int i = (end) - 1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = __uint128_t;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
template<class T> using max_heap = std::priority_queue<T>;
template<class T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T, class U> std::istream& operator>>(std::istream& in, std::pair<T, U>& p) { return in >> p.first >> p.second; }
template<class A, class B, class C> std::istream& operator>>(std::istream& in, std::tuple<A, B, C>& tp) { return in >> std::get<0>(tp) >> std::get<1>(tp) >> std::get<2>(tp); }
template<class T, int N> std::istream& operator>>(std::istream& in, std::array<T, N>& a) { for(T& x : a) in >> x; return in; }
template<class T> std::istream& operator>>(std::istream& in, std::vector<T>& a) { for(T& x : a) in >> x; return in; }

template<class Fun>
class y_combinator_result {
	Fun fun_;
	
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};

template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template<class T> bool chmin(T& a, const T& b) { return a > b ? (a = b, true) : false; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }
template<class T> std::vector<T> sort_unique(std::vector<T> v) { std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(), v.end()), v.end()); return v; }

namespace felix {}
using namespace std;

namespace felix {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_lct {
public:
	struct node_t {
		S val = e(), sum = e();
		F lz = id();
		bool rev = false;
		int sz = 1;
		node_t* l = nullptr;
		node_t* r = nullptr;
		node_t* p = nullptr;

		node_t() {}
		node_t(const S& s) : val(s), sum(s) {}

		bool is_root() const { return p == nullptr || (p->l != this && p->r != this); }
	};

	lazy_lct() : n(0) {}
	explicit lazy_lct(int _n) : lazy_lct(std::vector<S>(_n, e())) {}
	explicit lazy_lct(const std::vector<S>& v) : n(v.size()) {
		a.reserve(n);
		for(int i = 0; i < n; i++) {
			a.emplace_back(v[i]);
		}
	}

	node_t* access(int u) {
		assert(0 <= u && u < n);
		node_t* v = &a[u];
		node_t* last = nullptr;
		for(node_t* p = v; p != nullptr; p = p->p) {
			splay(p);
			p->r = last;
			pull(p);
			last = p;
		}
		splay(v);
		return last;
	}

	void make_root(int u) {
		access(u);
		a[u].rev ^= 1;
		push(&a[u]);
	}

	void link(int u, int v) {
		make_root(v);
		a[v].p = &a[u];
	}

	void cut(int u) {
		access(u);
		if(a[u].l != nullptr) {
			a[u].l->p = nullptr;
			a[u].l = nullptr;
			pull(&a[u]);
		}
	}

	void cut(int u, int v) {
		make_root(u);
		cut(v);
	}

	bool is_connected(int u, int v) {
		if(u == v) {
			return true;
		}
		access(u), access(v);
		return a[u].p != nullptr;
	}

	int get_lca(int u, int v) {
		if(u == v) {
			return u;
		}
		access(u);
		return access(v) - &a[0];
	}

	int get_root(int u) {
		node_t* v = access(u);
		push(v);
		while(v->l != nullptr) {
			v = v->l;
			push(v);
		}
		access(v);
		return v - &a[0];
	}

	int parent(int u) {
		access(u);
		return a[u].l - &a[0];
		node_t* cur = &a[u];
		while(true) {
			if(cur->r != nullptr) {
				cur = cur->r;
			} else if(cur->l != nullptr) {
				cur = cur->l;
			} else {
				return cur - &a[0];
			}
		}
	}

	void set(int u, const S& s) {
		access(u);
		a[u].val = s;
		pull(&a[u]);
	}

	S get(int u) {
		access(u);
		return a[u].val;
	}

	void apply(int u, int v, const F& f) {
		make_root(u);
		access(v);
		all_apply(&a[v], f);
		push(&a[v]);
	}

	S prod(int u, int v) {
		make_root(u);
		access(v);
		return a[v].sum;
	}

// private:
	int n;
	std::vector<node_t> a;

	void rotate(node_t* v) {
		auto attach = [&](node_t* p, bool side, node_t* c) {
			(side ? p->r : p->l) = c;
			pull(p);
			if(c != nullptr) {
				c->p = p;
			}
		};
		node_t* p = v->p;
		node_t* g = p->p;
		bool is_right = (p->r == v);
		bool is_root = p->is_root();
		attach(p, is_right, (is_right ? v->l : v->r));
		attach(v, !is_right, p);
		if(!is_root) {
			attach(g, (g->r == p), v);
		} else {
			v->p = g;
		}
	}

	void splay(node_t* v) {
		push(v);
		while(!v->is_root()) {
			auto p = v->p;
			auto g = p->p;
			if(!p->is_root()) {
				push(g);
			}
			push(p), push(v);
			if(!p->is_root()) {
				rotate((g->r == p) == (p->r == v) ? p : v);
			}
			rotate(v);
		}
	}

	void all_apply(node_t* v, F f) {
        // cout <<"all_apply" <<endl;
		v->val = mapping(f, v->val);
		v->sum = mapping(f, v->sum);
		v->lz = composition(f, v->lz);
	}

	void push(node_t* v) {
        // cout <<"push" <<endl;
		if(v->lz != id()) {
			if(v->l != nullptr) {
				all_apply(v->l, v->lz);
			}
			if(v->r != nullptr) {
				all_apply(v->r, v->lz);
			}
			v->lz = id();
		}
		if(v->rev) {
			std::swap(v->l, v->r);
			if(v->l != nullptr) {
				v->l->rev ^= 1;
			}
			if(v->r != nullptr) {
				v->r->rev ^= 1;
			}
			v->sum = reversal(v->sum);
			v->rev = false;
		}
	}

	void pull(node_t* v) {
        // cout <<"pull" <<endl;
		v->sz = 1;
		v->sum = v->val;
		if(v->l != nullptr) {
			push(v->l);
			v->sum = op(v->l->sum, v->sum);
			v->sz += v->l->sz;
		}
		if(v->r != nullptr) {
			push(v->r);
			v->sum = op(v->sum, v->r->sum);
			v->sz += v->r->sz;
		}
	}
};

} // namespace felix

using namespace felix;

using S = pair<int, int>;

S e() { return {0, 0}; }
S op(S a, S b) { return {a.first + b.first, a.second ^ b.second}; }
S reversal(S s) { return s; }

using F = bool;

F id() { return false; }
S mapping(F, S s) { return s; }
F composition(F, F) { return id(); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	lazy_lct<S, e, op, reversal, F, id, mapping, composition> lct(n);
	for(int i = 0; i < n; i++) {
		lct.set(i, {1, i});
	}
	int ans = 0;
	while(q--) {
		int A, B, C;
		cin >> A >> B >> C;

		int type = 1 + (((A * (1LL + ans)) % 998244353) % 2);
		int u = (((B * (1LL + ans)) % 998244353) % n);
		int v = (((C * (1LL + ans)) % 998244353) % n);

		// cerr << "Q " << type << " " << u + 1 << " " << v + 1 << endl;

		if(type == 1) {
			lct.link(u, v);
		} else {
			if(!lct.is_connected(u, v)) {
				ans = 0;
			} else {
				S res = lct.prod(u, v);
				if(res.first == 3) {
					ans = (res.second ^ u ^ v) + 1;
				} else {
					ans = 0;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}