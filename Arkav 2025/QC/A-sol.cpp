// Verified sama brute force
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e5 + 10;
const int maxC = 8;

struct Edge {
    ll weight[maxC];
};

vector<pair<int, int>> adj[maxN];
vector<pair<int, ll>> ancestors[maxN][maxC];
Edge edges[maxN];
int subtree_size[maxN], n, K, s;
bool is_removed[maxN], dijk[maxN];
ll dist[maxN][maxC], min_dist[maxN][maxC];
ll temp_dist[maxC], dist_dijk[maxN][maxC], res[maxN];

int get_subtree_size(int node, int parent = -1){
	subtree_size[node] = 1;
	for(auto &child: adj[node]){
		if(child.first == parent || is_removed[child.first]) continue;
		subtree_size[node] += get_subtree_size(child.first, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1){
	for(auto &child: adj[node]){
		if(child.first == parent || is_removed[child.first]) continue;
		if(subtree_size[child.first] * 2 > tree_size){
			return get_centroid(child.first, tree_size, node);
		}
	}
	return node;
}

void get_dists(int node, int centroid, int parent, ll cur_dist, int color){
	for(auto &child: adj[node]){
		if(child.first == parent || is_removed[child.first]) continue;
		cur_dist += edges[child.second].weight[color];
		get_dists(child.first, centroid, node, cur_dist, color);
		cur_dist -= edges[child.second].weight[color];
	}
	ancestors[node][color].push_back({centroid, cur_dist});
}

void build_centroid_decomp(int node = 1){
	int centroid = get_centroid(node, get_subtree_size(node));
	for(auto &child: adj[centroid]){
		if(is_removed[child.first]) continue;
		for(int c = 1; c <= K; c++){
            get_dists(child.first, centroid, centroid, edges[child.second].weight[c], c);
		}
	}
	is_removed[centroid] = 1;
	for(auto &child: adj[centroid]){
		if(is_removed[child.first]) continue;
		build_centroid_decomp(child.first);
	}
}

ll query(int node, ll ans, int c){
    for(auto &dist: ancestors[node][c]){
        if(min_dist[dist.first][c] == LLONG_MAX) continue;
        ans = min(ans, min_dist[dist.first][c] + dist.second);
    }
    if(min_dist[node][c] != LLONG_MAX){
        ans = min(min_dist[node][c], ans);
    }
    return ans;
}

void update(int node, ll mini, int c){
    for(auto &dist: ancestors[node][c]){
        min_dist[dist.first][c] = min(min_dist[dist.first][c], mini + dist.second);
    }
    min_dist[node][c] = min(min_dist[node][c], mini);
}

int main(){
    cin >> n >> K >> s;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        for(int c = 1; c <= K; c++){
            cin >> edges[i].weight[c];
        }
    }
    for(int i = 1; i <= K; i++) {
        for(int node = 1; node <= n; node++){
            cin >> dist[node][i];
        }
    }
    build_centroid_decomp();
    for(int node = 1; node <= n; node++){
        for(int c = 1; c <= K; c++){
            min_dist[node][c] = LLONG_MAX;
        }
    }
    priority_queue< pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
    for(int color = 1; color <= K; color++){
        memset(dijk, 0, n + 1);
        pq.push({0, s});
        while(!pq.empty()){
            pair<ll, int> fi = pq.top();
            pq.pop();
            if(dijk[fi.second]) continue;
            dijk[fi.second] = 1;
            dist_dijk[fi.second][color] = fi.first;
            for(auto &child: adj[fi.second]){
                pq.push({fi.first + edges[child.second].weight[color], child.first});
            }
        }
    }
    for(int node = 1; node <= n; node++){
        ll ans = LLONG_MAX;
        for(int c = 1; c <= K; c++){
            ll mini = query(node, dist_dijk[node][c], c);
            temp_dist[c] = mini;
            ans = min(ans, mini);
        }
        for(int c1 = 1; c1 <= K; c1++){
            ll cur_mini = LLONG_MAX;
            for(int c2 = 1; c2 <= K; c2++){
                ll switch_cost = 0;
                if(c1 != c2) {
                    switch_cost = dist[node][c2];
                }
                cur_mini = min(cur_mini, temp_dist[c2] + switch_cost);
            }
            update(node, cur_mini, c1);
        }
        res[node] = ans;
    }
    for(int node = 1; node <= n; node++){
        cout << res[node];
        if(node != n) cout << " ";
    }
    cout << '\n';
    return 0;
}
