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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}
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
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int mxn=1e5;
int n,q;
vector<int> adj[mxn];
int sub[mxn], ch[mxn];
FT f(mxn);

Tree<int> s1[mxn],s2[mxn];
ll ans[mxn];
vector<pii> qry1[mxn];
vector<piii> qry2[mxn];

void dfs1(int u, int p=-1) {
    sub[u] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs1(v,u);
        sub[u] +=sub[v];
    }
}

void dfs2(int u, int p=-1) {
    for(auto [num,id]: qry1[u]) {
        int l=0,r=n-1;
        int lca=-1, num2;
        while(l<=r) {
            int mid = (l+r)/2;
            int ct = f.query(mid+1);
            if(ct-1>=num) {
                lca = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        num2 = num - f.query(lca);
        qry2[lca].push_back({{ch[lca],num2},id});
    }
    for(int v: adj[u]) {
        if(v==p) continue;
        ch[u] = v;
        f.update(u,sub[v]*-1);
        f.update(v,sub[v]);
        dfs2(v,u);
        f.update(v,sub[v]*-1);
        f.update(u,sub[v]);
    }
}

// small-to-large
void join(Tree<int>& sa, Tree<int>& sb) {
    if(sz(sa)<sz(sb)) sa.swap(sb);
    for(auto sbi : sb) sa.insert(sbi);
}

void dfs3(int u, int p=-1) {
    s1[u].insert(u);
    s2[u].insert(u);
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs3(v,u);
        join(s1[u],s1[v]);
    }
    for(auto [chnum, id]: qry2[u]) {
        auto [chi,num] = chnum;
        int l=0,r=n-1;
        int y=-1;
        while(l<=r) {
            int mid = (l+r)/2;
            int ctu = s1[u].order_of_key(mid);
            int ctch = chi==-1?0:s2[chi].order_of_key(mid);
            if(ctu-ctch>num) {
                r = mid-1;
            } else {
                y = mid;
                l = mid+1;
            }
        }
        // cout <<id <<" " <<u <<" " <<y <<"\n";
        ans[id] += 1ll*u*n + y;
    }
    for(int v: adj[u]) {
        if(v==p) continue;
        join(s2[u],s2[v]);
    }
}

void solve() {
    cin >>n >>q;
    int rt=-1;
    rep(i,0,n) {
        int pi; cin >>pi; pi--;
        if(pi==-1) {
            rt = i;
            continue;
        }
        adj[pi].push_back(i);
    }
    dfs1(rt);
    rep(i,0,q) {
        ll ki; cin >>ki; ki--;
        ll num = ki%n;
        ll u = ki/n;
        qry1[u].push_back({num,i});
        ans[i] += u*n*n;
    }
    f.update(rt,n);
    rep(i,0,n) {
        ch[i] = -1;
    }
    dfs2(rt);
    dfs3(rt);
    rep(i,0,q) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}