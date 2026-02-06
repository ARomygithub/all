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

const int mxn=500;
const int di[8] = {-1,0,1,0,-1,1,1,-1}, dj[8] = {0,1,0,-1,1,1,-1,-1};
int n,m;
bool vis[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&vis[i][j];
}

void dfs(pii u, int& ct) {
    vis[u.fi][u.se] = 0;
    ct++;
    for(int k=0;k<8;k++) {
        int ii = u.fi+di[k], jj=u.se+dj[k];
        if(e(ii,jj)) {
            dfs({ii,jj},ct);
        }
    }
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>vis[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(vis[i][j]) {
                int temp=0;
                dfs({i,j}, temp);
                max_self(ans,temp);
            }
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