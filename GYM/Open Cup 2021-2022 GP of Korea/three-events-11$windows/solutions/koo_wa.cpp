#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int MAXT = 530000;

int n, a[3][MAXN];

struct seg{
	pi tree[MAXT];
	int lim;
	void init(int n){
		fill(tree, tree + MAXT, pi(1e9, -1));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void upd(int x, pi v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	pi query(int s, int e){
		s += lim;
		e += lim;
		pi ret(1e9, -1);
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}seg[3];

bool vis[MAXN];
int comp[MAXN];
vector<int> dfn;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	vector<int> to_visit;
	for(int i = 0; i < 3; i++){
		int k = a[i][x], v = a[(i+1)%3][x];
		pi qr;
		while((qr = seg[i].query(1, k - 1)).first < v){
			to_visit.push_back(qr.second);
			seg[i].upd(a[i][qr.second], pi(1e9, -1));
		}
	}
	for(auto &y : to_visit) dfs(y);
	dfn.push_back(x);
}

void rdfs(int x, int p){
	if(comp[x]) return;
	comp[x] = p;
	vector<int> to_visit;
	for(int i = 0; i < 3; i++){
		int k = a[i][x], v = a[(i+1)%3][x];
		pi qr;
		while((qr = seg[i].query(k + 1, n)).first < -v){
			to_visit.push_back(qr.second);
			seg[i].upd(a[i][qr.second], pi(1e9, -1));
		}
	}
	for(auto &y : to_visit) rdfs(y, p);
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d",&a[j][i]);
		}
	}
	for(int i = 0; i < 3; i++){
		seg[i].init(n);
		for(int j = 1; j <= n; j++){
			seg[i].upd(a[i][j], pi(a[(i+1)%3][j], j));
		}
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			for(int j = 0; j < 3; j++){
				seg[j].upd(a[j][i], pi(1e9, -1));
			}
			dfs(i);
		}
	}
	for(int i = 0; i < 3; i++){
		seg[i].init(n);
		for(int j = 1; j <= n; j++){
			seg[i].upd(a[i][j], pi(-a[(i+1)%3][j], j));
		}
	}
	reverse(all(dfn));
	int piv = 0;
	for(auto &i : dfn){
		if(!comp[i]){
			for(int j = 0; j < 3; j++){
				seg[j].upd(a[j][i], pi(1e9, -1));
			}
			rdfs(i, ++piv);
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		puts(comp[x] >= comp[y] ? "YES" : "NO");
	}
}
