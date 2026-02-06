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

const int mxn=2e5,mxa=1e6;
int n,m;
vector<int> adj[mxn];
set<int> s;
int ans=0;

void dfs(int u=0) {
    s.insert(u);
    ans++;
    for(int v: adj[u]) {
        if(s.find(v)==s.end()) {
            if(ans>=mxa) return;
            dfs(v);
        }
    }
    s.erase(u);
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}