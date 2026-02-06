#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3, inf = 1e9+3;
int n;
int a[maxn], sa[maxn];
int tree[4*maxn];
int lis;
int dpl[maxn], dpr[maxn];
int mnv[maxn];

int id(int x) {
	return lower_bound(sa, sa+n, x) - sa;
}

int query(int ql, int qr, int l = 0, int r = n-1, int v = 1) {
	if (ql > qr || r < ql || l > qr) return 0;
	if (l >= ql && r <= qr) return tree[v];
	int mid = (l+r)/2;
	return max(query(ql, qr, l, mid, v*2), query(ql, qr, mid+1, r, v*2+1));
}

void update(int pos, int val, int l = 0, int r = n-1, int v = 1) {
	if (l == r) tree[v] = val;
	else {
		int mid = (l+r)/2;
		if (pos <= mid) update(pos, val, l, mid, v*2);
		else update(pos, val, mid+1, r, v*2+1);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];

	for (int i=0; i<n; i++) sa[i] = a[i];
	sort(sa, sa+n);

	memset(tree, 0, sizeof tree);
	for (int i=0; i<n; i++) {
		int j = id(a[i]);
		dpl[i] = query(0, j-1) + 1;
		update(j, dpl[i]);
	}

	memset(tree, 0, sizeof tree);
	for (int i=n-1; i>=0; i--) {
		int j = id(a[i]);
		dpr[i] = query(j+1, n-1) + 1;
		update(j, dpr[i]);
	}
	// assert(dpr[0] == dpl[n-1]);

	lis = 0;
	for (int i=0; i<n; i++) lis = max(lis, dpl[i]);

	for (int i=1; i<n; i++) {
		if (dpr[i] == lis) {
			cout << lis + 1 << '\n';
			return 0;
		}
	}

	for (int i=0; i+1<n; i++) {
		if (dpl[i] == lis) {
			cout << lis + 1 << '\n';
			return 0;
		}
	}

	for (int i=0; i<=n; i++) mnv[i] = inf;
	for (int i=0; i<n; i++) {
		int look = lis - dpr[i];
		if (mnv[look]+1 < a[i]) {
			cout << lis + 1 << '\n';
			return 0;
		}
		if (i-1 >= 0) {
			mnv[dpl[i-1]] = min(mnv[dpl[i-1]], a[i-1]);
		}
	}

	cout << lis << '\n';
	return 0;
}

/*
5
1 2 3 4 5

5
2 2 3 4 5

5
1 2 3 4 4

5
1 2 0 4 5

5
1 2 0 3 5

5
1 2 0 3 4
*/