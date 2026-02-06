#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n,m;
vector<string> s;
vector<vector<bool>> vis;

void dfs(int i, int j) {
    vis[i][j] = 1;
    if(i+1<n && !vis[i+1][j] && s[i+1][j]=='.') {
        dfs(i+1,j);
    }
    if(j+1<m && !vis[i][j+1] && s[i][j+1]=='.') {
        dfs(i,j+1);
    }
}

void dfs2(int i, int j, set<pii> &st) {
    if(j>0 && vis[i][j-1]) {
        st.insert({i,j-1});
        dfs2(i,j-1,st);
    } else if(i>0 && vis[i-1][j]) {
        st.insert({i-1,j});
        dfs2(i-1,j,st);
    }
}

void dfs3(int i, int j, set<pii> &st) {
    if(i>0 && vis[i-1][j]) {
        st.insert({i-1,j});
        dfs3(i-1,j,st);
    } else if(j>0 && vis[i][j-1]) {
        st.insert({i,j-1});
        dfs3(i,j-1,st);
    }
}

void solve() {
    cin >>n >>m;
    s.resize(n);
    for(int i=0;i<n;i++) {
        cin >>s[i];
    } 
    vis.resize(n);
    for(int i=0;i<n;i++) {
        vis[i] = vector<bool>(m,0);
    }
    dfs(0,0);
    int ans=0;
    if(vis[n-1][m-1]) {
        set<pii> st;
        dfs2(n-1,m-1,st);
        dfs3(n-1,m-1,st);
        // cout <<sz(st) <<"\n";
        // for(auto [a,b]: st) {
        //     cout <<a <<" " <<b <<"\n";
        // }
        if(sz(st)-1<(n+m-3)*2) {
            ans = 1;
        } else {
            ans = 2;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}