#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 100100;
int n;
ll a[N][2];
bool used[N];
ll W;
ll ans = 0;
map<ll, set<pli>> b1, b2;
map<ll, vector<ll>> c1, c2;

void dfs(int v)
{
	used[v] = 1;

	ll x = a[v][0];
	ll y = a[v][1];

	while(true)
	{
		auto it = b1[x - W].lower_bound(mp(y - W, -1));
		if (it == b1[x - W].end() || it->first > y + W) break;
		int u = it->second;
		b1[x - W].erase(it);
		if (!used[u]) dfs(u);
	}


	while(true)
	{
		auto it = b1[x + W].lower_bound(mp(y - W, -1));
		if (it == b1[x + W].end() || it->first > y + W) break;
		int u = it->second;
		b1[x + W].erase(it);
		if (!used[u]) dfs(u);
	}


	while(true)
	{
		auto it = b2[y - W].lower_bound(mp(x - W, -1));
		if (it == b2[y - W].end() || it->first > x + W) break;
		int u = it->second;
		b2[y - W].erase(it);
		if (!used[u]) dfs(u);
	}


	while(true)
	{
		auto it = b2[y + W].lower_bound(mp(x - W, -1));
		if (it == b2[y + W].end() || it->first > x + W) break;
		int u = it->second;
		b2[y + W].erase(it);
		if (!used[u]) dfs(u);
	}

	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int V, U;
	scanf("%d%d", &V, &U);
	V--;U--;
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		a[i][0] = x + y;
		a[i][1] = x - y;
		x = a[i][0];
		y = a[i][1];
		b1[x].insert(mp(y, i));
		c1[x].push_back(y);
		b2[y].insert(mp(x, i));
		c2[y].push_back(x);
	}
	for (auto it : c1)
		sort(c1[it.first].begin(), c1[it.first].end());
	for (auto it : c2)
		sort(c2[it.first].begin(), c2[it.first].end());
	W = max(abs(a[V][0] - a[U][0]), abs(a[V][1] - a[U][1]));
	dfs(V);

	for (int v = 0; v < n; v++)
	{
		if (!used[v]) continue;
//		printf("%d ", v);
		ll x = a[v][0], y = a[v][1];
		ans += upper_bound(c1[x - W].begin(), c1[x - W].end(), y + W) - lower_bound(c1[x - W].begin(), c1[x - W].end(), y - W);
		ans += upper_bound(c1[x + W].begin(), c1[x + W].end(), y + W) - lower_bound(c1[x + W].begin(), c1[x + W].end(), y - W);
		ans += lower_bound(c2[y - W].begin(), c2[y - W].end(), x + W) - upper_bound(c2[y - W].begin(), c2[y - W].end(), x - W);
		ans += lower_bound(c2[y + W].begin(), c2[y + W].end(), x + W) - upper_bound(c2[y + W].begin(), c2[y + W].end(), x - W);
	}
	printf("%lld\n", ans / 2);

	return 0;
}