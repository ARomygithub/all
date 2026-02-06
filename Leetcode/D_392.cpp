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

struct UF {
	vi e, ans;
	UF(int n) : e(n, -1), ans(n,(1<<17)-1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b, int w) {
		a = find(a), b = find(b);
		if (a == b) {
            ans[a] = ans[a]&w;
            return false;
        }
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        ans[a] = ans[a]&ans[b]&w;
		return true;
	}
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UF uf(n);
        rep(i,0,sz(edges)) {
            uf.join(edges[i][0],edges[i][1],edges[i][2]);
        }
        vector<int> ans(sz(query));
        rep(i,0,sz(query)) {
            int u = query[i][0], v = query[i][1];
            if(u==v) {
                ans[i] = 0;
            } else if(uf.sameSet(u,v)) {
                ans[i] = uf.ans[uf.find(u)];
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}