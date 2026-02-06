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

const int mxn=10;
int n,m,t;
int grid[mxn][mxn];
bool vis[mxn][mxn];
int ct = 0;
const int di[] = {-1,0,1,0, -1,1,1,-1}, dj[] = {0,1,0,-1, 1,1,-1,-1};

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&(!vis[i][j])&&(grid[i][j]==1);
}

void dfs(int i, int j) {
    vis[i][j] = 1;
    ct++;
    rep(k,0,8) {
        int ii = i+di[k], jj= j+dj[k];
        if(e(ii,jj)) {
            dfs(ii,jj);
        }
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>grid[i][j];
        }
    }
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            if(!vis[i][j] && grid[i][j]==1) {
                ct = 0;
                dfs(i,j);
                max_self(ans, ct);
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    // while(t--) {
        solve();
    // }
}