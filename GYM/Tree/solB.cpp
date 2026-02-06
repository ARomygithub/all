#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    Node() : dist(0) {}
    int dist;
    vector<int> adj;
};
 
 
void dfs(vector< Node >& a, int dist, int curr, int p = -1) {
    a[curr].dist = dist;
    for (auto v : a[curr].adj) {
        if (v != p) dfs(a, dist + 1, v, curr);
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u - 1].adj.push_back(v - 1);
        a[v - 1].adj.push_back(u - 1);
    }
 
    // convenience lambda for finding the maximal distance and its node index
    auto getMaxDistIndex = [](const vector<Node>& a) -> pair<int, int> {
        int maxDist = -1;
        int maxIndex = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].dist > maxDist) {
                maxDist = a[i].dist;
                maxIndex = i;
            }
        }
        return { maxDist, maxIndex };
    };
 
    // find first diameter endpoint
    dfs(a, 0, 0);
    auto maxDistIndex = getMaxDistIndex(a);
 
    // run distance calculation from here
    dfs(a, 0, maxDistIndex.second);
    maxDistIndex = getMaxDistIndex(a);
    auto diameter = maxDistIndex.first;
    // run second diameter calculation from any of the leaves. copy whole graph since we are lazy
    auto b = a;
    dfs(b, 0, maxDistIndex.second);
    
 
    for (int i = 0; i < n; i++) {
        // if we add to a node that is either "diameter" steps away from our first or second root then we extend diameter by 1
        if (a[i].dist == diameter || b[i].dist == diameter) {
            cout << diameter + 1 << "\n";
        }
        else {
            cout << diameter << "\n";
        }
    }
    
    return 0;
}
 