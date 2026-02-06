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

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = sz(edges1)+1, m=sz(edges2)+1;
        vector adj1(n, vector<int>());
        rep(i,0,sz(edges1)) {
            int u = edges1[i][0], v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<int> d1(n,0);
        int diam1 = 0;
        function<void(int,int)> dfs1;
        dfs1 = [&](int u, int p) -> void {
            for(int b: adj1[u]) {
                if(b==p) continue;
                dfs1(b,u);
                max_self(diam1, d1[u]+d1[b]+1);
                max_self(d1[u], d1[b]+1);
            }
        };
        dfs1(0,-1);

        vector adj2(m, vector<int>());
        rep(i,0,sz(edges2)) {
            int u = edges2[i][0], v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int> d2(m,0);
        int diam2 = 0;
        function<void(int,int)> dfs2;
        dfs2 = [&](int u, int p) -> void {
            for(int b: adj2[u]) {
                if(b==p) continue;
                dfs2(b,u);
                max_self(diam2, d2[u]+d2[b]+1);
                max_self(d2[u], d2[b]+1);
            }
        };
        dfs2(0,-1);
        int ans = max(diam1,diam2);
        max_self(ans, (diam1+1)/2 + (diam2+1)/2 + 1);
        return ans;        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}