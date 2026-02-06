#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m,t;
int in[mxn];
vector<pii> adj[mxn];
vector<int> adj2[mxn];
bool vis[mxn];
int ct=0;

void dfs(int u=0) {
    vis[u] = 1;
    ct++;
    for(int v: adj2[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        in[v]++;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    dfs();
    if(ct==n) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<n;i++) {
            if(in[i]==0) {
                int temp = 1e9;
                for(auto [wi,vi]: adj[i]) {
                    min_self(temp,wi);
                }
                pq.push({temp,i});
            }
        }
        vector<int> v;
        ll ans=0;
        while(sz(q)>1) {
            int u = q.front(); q.pop();
            int temp=1e9;
            for(auto [wi,vi]: adj[u]) {
                min_self(temp,wi)
            }
        }
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}