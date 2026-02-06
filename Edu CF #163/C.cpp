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

const int mxn=2e5;
const int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int n,t;
string s[2];

bool e(int i, int j) {
    return i>=0&&i<2&&j>=0&&j<n;
}

void solve() {
    cin >>n;
    cin >>s[0];
    cin >>s[1];
    vector vis(2, vector<bool>(n,0));
    function<void(pii)> dfs;
    dfs = [&](pii u) -> void {
        vis[u.fi][u.se] = 1;
        rep(i,0,4) {
            int ui = u.fi+di[i];
            int uj = u.se+dj[i];
            if(e(ui,uj)) {
                if(s[ui][uj]=='>') {
                    uj++;
                } else {
                    uj--;
                }
                if(!vis[ui][uj]) {
                    dfs({ui,uj});
                }
            }
        }
    };
    dfs({0,0});
    if(vis[1][n-1]) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
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