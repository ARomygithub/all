#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define piii pair<int,pii>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e3;
int n,m,t;
int c[mxn+1];
vector<int> adj1[mxn+1],adj2[mxn+1];

void tesclear() {
    for(int i=1;i<=n;i++) {
        adj1[i].clear();
        adj2[i].clear();
    }
}

void solve() {
    cin >>n >>m;
    for(int i=1;i<=n;i++) {
        cin >>c[i];
    }
    for(int i=1;i<=m;i++) {
        int u,v; cin >>u >>v;
        if(c[v]==1) {
            adj2[u].push_back(v);
        } else {
            adj1[u].push_back(v);
        }
        if(c[u]==1) {
            adj2[v].push_back(u);
        } else {
            adj1[v].push_back(u);
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
    if(c[1]==c[n]) {
        cout <<"-1\n";
        tesclear();
        return;
    }
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    dp[1][n] = 0;
    pq.push({0,{1,n}});
    while(sz(pq)) {
        auto [w,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        if(dp[i][j]<w) continue;
        for(auto ui: adj1[i]) {
            for(auto uj: adj2[j]) {
                if(dp[ui][uj]>w+1) {
                    dp[ui][uj] = w+1;
                    pq.push({dp[ui][uj],{ui,uj}});
                }
            }
        }
        for(auto ui: adj2[i]) {
            for(auto uj: adj1[j]) {
                if(dp[ui][uj]>w+1) {
                    dp[ui][uj] = w+1;
                    pq.push({dp[ui][uj],{ui,uj}});
                }
            }
        }        
    }
    if(dp[n][1]==1e9) {
        cout <<"-1\n";
    } else {
        cout <<dp[n][1] <<"\n";
    }
    tesclear();
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