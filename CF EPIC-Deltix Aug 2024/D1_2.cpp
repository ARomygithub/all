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

const int mxn=65535;
int n,q,t;
int a[mxn+1],p[mxn+1];
map<int,int> toId,toU,idx;

struct Tree {
	typedef pii T;
	static constexpr T unit = {INT_MIN, INT_MAX};
	T f(T a, T b) { return {max(a.fi,b.fi),min(a.se,b.se)}; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void dfs(int u, int& id, int dep) {
    toId[u] = id;
    toU[id] = u;
    idx[u] = dep;
    id++;
    if(u*2<=n) {
        dfs(u*2,id,dep+1);
        dfs(u*2+1,id,dep+1);
    }
}

void solve() {
    cin >>n >>q;
    rep(i,2,n+1) {
        cin >>a[i];
    }
    rep(i,1,n+1) {
        cin >>p[i];
    }
    vector<Tree> vt(16, Tree(n+1));
    rep(i,1,n+1) {
        int u = p[i];
        per(j,15,-1) {
            while(u >= (1<<(j+1))) {
                u /=2;
            }
            vt[j].update(i, {u,u});
        }
    }
    int id = 1;
    dfs(1,id, 0);
    int pr = 0;
    vector<bool> vpr(n+1,0);
    int k = idx[n]+1;
    rep(i,1,n+1) {
        int le = toId[i];
        int dep = idx[i];
        int ri = le + (1<<(k-dep))-1;
        auto mn = vt[15].query(le,ri).se;
        auto [mxi,mni] = vt[dep].query(le,ri);
        bool er = mn!=p[le] || mxi!=p[le] || mni!=p[le];
        if(er) {
            vpr[i] = 1;
            pr++;
        }
    }
    auto upd = [&](int x) -> void {
        int u = p[x];
        per(j,15,-1) {
            while(u >= (1<<(j+1))) {
                u /=2;
            }
            vt[j].update(x, {u,u});
        }
    };
    auto getEr = [&](int i) -> bool {
        int le = toId[i];
        int dep = idx[i];
        int ri = le + (1<<(k-dep))-1;
        auto mn = vt[15].query(le,ri).se;
        auto [mxi,mni] = vt[dep].query(le,ri);
        bool er = mn!=p[le] || mxi!=p[le] || mni!=p[le];
        return er;        
    };
    auto recalc = [&](int u) -> void {
        while(u) {
            bool er = getEr(u);
            if(er!=vpr[u]) {
                if(er) {
                    pr++;
                } else {
                    pr--;
                }
                vpr[u] = er;
            }
            u /=2;
        }
    };
    while(q--) {
        int x,y; cin >>x >>y;
        swap(p[x],p[y]);
        upd(x); upd(y);
        recalc(toU[x]); recalc(toU[y]);
        if(pr==0) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}