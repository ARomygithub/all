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

const int mxn=1e6;
int n;
int dp[mxn+1];
bool vis[mxn+1];

int find(int x) {
    if(x==0) return 0;
    if(x<10) return 1;
    if(vis[x]) return dp[x];
    set<int> s;
    int u = x;
    while(u) {
        if(u%10!=0) s.insert(u%10);
        u /=10;
    }
    vis[x] = 1;
    dp[x] = 1e9;
    for(auto b : s) {
        min_self(dp[x],1+find(x-b));
    }
    return dp[x];
}

void solve() {
    cin >>n;
    cout <<find(n) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}