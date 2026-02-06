#include<bits/stdc++.h>

const int mxa=1e5;
vector<int> adj[mxa];
int timer = 0, tin[mxa], eul[2*mxa], tout[mxa];

void dfs(int node = 0, int parent = -1) {
	tin[node] = timer; // The time when we first visit a node
	eul[timer++] = node;
	for (int i : adj[node]) {
		if (i != parent) {
			dfs(i, node);
			eul[timer++] = node;
		}
	}
    tout[node] = timer-1;
}