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

class Solution {
public:
    void dfs(int u, int p, int& ct, vi& sub, vector<vi>& adj) {
        sub[u] = 1;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs(v,u, ct, sub, adj);
            sub[u] += sub[v];
        }
        set<int> st;
        for(int v: adj[u]) {
            if(v==p) continue;
            st.insert(sub[v]);
            if(sz(st)>1) break;
        }
        ct += sz(st)<=1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = sz(edges)+1;
        vector sub(n, 0);
        vector<vi> adj(n);
        for(auto edi: edges) {
            adj[edi[0]].push_back(edi[1]);
            adj[edi[1]].push_back(edi[0]);
        }
        int ct = 0;
        dfs(0, -1, ct, sub, adj);
        return ct;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}