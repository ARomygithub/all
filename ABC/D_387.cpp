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

const int mxn=1e3;
int n,m;
string s[mxn];
using pipi = pair<pii,pii>;

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]!='#';
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    pii st, gl;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='S') {
                st = {i,j};
            } else if(s[i][j]=='G') {
                gl = {i,j};
            }
        }
    }
    vector dp(n, vector(m, vi(2,1e9)));
    priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
    rep(i,0,2) {
        dp[st.fi][st.se][i] = 0;
        pq.push({{0,i},st});
    }
    while(sz(pq)) {
        auto [db,ij] = pq.top(); pq.pop();
        auto [d,b] = db;
        auto [i,j] = ij;
        if(dp[i][j][b]<d) continue;
        if(b) {
            for(auto j2: vi{j-1,j+1}) {
                if(e(i,j2)) {
                    if(dp[i][j2][1-b]> d+1) {
                        dp[i][j2][1-b] = d+1;
                        pq.push({{d+1,1-b},{i,j2}});
                    }
                }
            }
        } else {
            for(auto i2: vi{i-1,i+1}) {
                if(e(i2,j)) {
                    if(dp[i2][j][1-b]>d+1) {
                        dp[i2][j][1-b] = d+1;
                        pq.push({{d+1,1-b},{i2,j}});
                    }
                }
            }
        }
    }
    int ans = min(dp[gl.fi][gl.se][0],dp[gl.fi][gl.se][1]);
    if(ans==1e9) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}