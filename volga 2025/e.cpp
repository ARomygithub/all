#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int di[3] = {0,1,0}, dj[3] = {1,0,-1};
int n,m,k;

void solve() {
    cin >>n >>m >>k;
    vector<string> vs(n);    
    rep(i,0,n) {
        cin >>vs[i];
    }
    rep(j,0,m) {
        int lws = n;
        per(i,n-1,-1) {
            if(vs[i][j]=='x') {
                lws = i;
            }
            if(lws-i <=k-1) {
                vs[i][j] = 'x';
            }
        }
    }
    auto e = [&](int i, int j) -> bool {
        return i>=0&&i<n&&j>=0&&j<m&&vs[i][j]=='.';
    };
    int mx = 0;
    function<void(int,int)> dfs;
    dfs = [&](int i, int j) -> void {
        vs[i][j] = 'x';
        max_self(mx, i);
        rep(l,0,3) {
            int ii = i+di[l], jj = j+dj[l];
            if(e(ii,jj)) {
                dfs(ii,jj);
            }
        }
    };
    dfs(0,0);
    cout <<mx+k <<"\n";
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}