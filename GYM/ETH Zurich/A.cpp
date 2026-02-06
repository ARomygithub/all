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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

const ll mod = 998244353;
ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}
ll inv(ll a) {
    return fastexpo(a, mod-2);
}

struct LCA {
	int T = 0;
	vi time, path, ret, pi, ct0;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)), pi(sz(C)), ct0(sz(C),0) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		pi[v] = sz(C[v])-1;
        if(pi[v]==0) {
            ct0[v] = 1;
            pi[v] = 1;
        }
        if(par!=-1) {
            pi[v] = 1ll*pi[v]*pi[par]%mod;
            ct0[v] += ct0[par];
        }
        for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}

    ll qry(vector<vi>& C, int a, int b) {
        int lca2 = lca(a,b);
        ll ans = 1ll*pi[a]*pi[b]%mod;
        ll ct0i = ct0[a]+ct0[b] - ct0[lca2]*2;
        ans = ans*inv(pi[lca2])%mod; 
        ans = ans*inv(pi[lca2])%mod;
        if(sz(C[lca2])-1 == 0) {
            ct0i++;
        } else {
            ans = ans*(sz(C[lca2])-1)%mod;
        }
        if(sz(C[b])-1 == 0) {
            ct0i--;
        } else {
            ans = ans*inv(sz(C[b])-1)%mod;
        }
        // debug() <<imie(ans) <<imie(ct0i);
        if(sz(C[a])-1 == 0) {
            ct0i--;
        } else {
            ans = ans*inv(sz(C[a])-1)%mod;
        }
        // debug() <<imie(ans) <<imie(ct0i);
        ans = ans*sz(C[a])%mod;
        // debug() <<imie(ans) <<imie(ct0i);
        if(ct0i>0) {
            ans = 0;
        }        
        return ans;
    }
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

const int mxn=1e5;
int n,q;
vector<vi> C;

void solve() {
    cin >>n >>q;
    C.resize(n);
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        C[u].push_back(v);
        C[v].push_back(u);
    }
    LCA lca(C);
    while(q--) {
        int a,b; cin >>a >>b; a--,b--;
        ll qry = lca.qry(C,a,b);
        cout <<qry <<"\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}