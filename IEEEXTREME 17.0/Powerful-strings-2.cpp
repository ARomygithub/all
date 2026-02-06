#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const int mxn=2e3+5;
const ll mod=998244353;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

template<class T> struct Matrix {
	typedef Matrix M;
	int N;
	vector<vector<T>> d;
	Matrix(int N) {
		this->N = N;
		d.resize(N,vector<T>(N,0));
	}
	M operator*(const M& m) const {
		M a(N);
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) {
				ll temp = d[i][k]*m.d[k][j]%mod;
				a.d[i][j] = (a.d[i][j]+temp)%mod;
			}
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		vector<T> ret(N);
		rep(i,0,N) rep(j,0,N) ret[i] += d[i][j] * vec[j];
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a(N), b(N);
		rep(i,0,N) {
			rep(j,0,N) {
				b.d[i][j] = this->d[i][j];
			}
		}
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

struct AhoCorasick {
	enum {alpha = 26, first = 'a'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		ll ct=0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	ll getAns(ll nn) {
		ll ans=0;
		int n = 0;
		N[n].ct = 1;
		function<void(int, int)> dfs;
		dfs = [&](int u, int k) -> void {
			ll ctu = N[u].ct;
			N[u].ct = 0;
			if(k==0) {
				ans = (ans + ctu)%mod;
				return;
			}
			rep(i,0,alpha) {
				int v = N[u].next[i];
				N[v].ct = ctu*fastexpo(2ll,N[v].nmatches)%mod;
				dfs(v,k-1);
			}
		};
		dfs(n,nn);
		return ans;
	}
};

void solve() {
	ll nn,m; cin >>nn >>m;
    vector<string> pat(m);
	rep(i,0,m) {
		cin >>pat[i];
	}
    AhoCorasick ac(pat);
	// debug() <<imie(ac.N);
	// rep(i,0,sz(ac.N)) {
	// 	cout <<ac.N[i].start <<" " <<ac.N[i].end <<" " <<ac.N[i].nmatches <<"\n";
	// 	rep(j,0,26) {
	// 		cout <<ac.N[i].next[j] <<" \n"[j==25];
	// 	}
	// }
	Matrix<ll> mat(sz(ac.N));
	rep(i,0,sz(ac.N)) {
		map<int,int> mp;
		rep(j,0,ac.alpha) {
			int v = ac.N[i].next[j];
			mp[v]++;
		}
		for(auto [k,v]: mp) {
			mat.d[i][k] = 1ll*v*fastexpo(2ll,ac.N[k].nmatches)%mod;
			// cout <<mat.d[i][k] <<"\n";
		}
	}
	auto mat2 = mat^nn;
	ll ans=0;
	rep(i,0,sz(ac.N)) {
		ans = (ans+mat2.d[0][i])%mod;
	}
	cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}