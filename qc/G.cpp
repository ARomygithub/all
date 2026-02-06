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

const int mxn=3e5;
int n,m;
ll a[mxn+1], dp[mxn+1];
vector<int> adj[mxn+1];
int in[mxn+1];

void solve() {
    cin >>n >>m;
    ll mx=0;
    for(int i=0;i<n;i++) {
        cin >>a[i+1];
    }
    for(int i=1;i<=n;i++) {
        int b; cin >>b;
        dp[b] +=a[i];
        max_self(mx,dp[b]);
    }
    for(int i=1;i<m;i++) {
        int u,v; cin >>u >>v;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for(int i=1;i<=m;i++) {
        if(in[i]==0) {
            q.push(i);
        }
    }
    while(sz(q)) {
        int u = q.front(); q.pop();
        for(auto v: adj[u]) {
            dp[v] +=dp[u];
            max_self(mx,dp[v]);
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    set<int> ans;
    for(int i=1;i<=m;i++) {
        if(dp[i]==mx) ans.insert(i);
    }
    cout <<sz(ans) <<"\n";
    for(auto it=ans.begin();it!=ans.end();it++) {
        if(it==ans.begin()) {
            cout <<*it;
        } else {
            cout <<" " <<*it;
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}