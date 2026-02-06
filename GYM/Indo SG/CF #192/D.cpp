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
typedef pair<int,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
const int di[4]={-1,0,1,0}, dj[4]={0,1,0,-1};
int n,m;
string s[mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]!='T';
}

void solve() {
    cin >>n >>m;
    pii st,en;
    rep(i,0,n) {
        cin >>s[i];
        rep(j,0,m) {
            if(s[i][j]=='S') {
                st = {i,j};
            } else if(s[i][j]=='E') {
                en = {i,j};
            }
        }
    }
    vector dp(n, vector<int>(m,1e9));
    priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
    dp[en.fi][en.se] = 0;
    pq.push({0,en});
    while(sz(pq)) {
        auto [w, u] = pq.top(); pq.pop();
        if(dp[u.fi][u.se]<w) continue;
        rep(k,0,4) {
            int ii = u.fi+di[k], jj = u.se+dj[k];
            if(e(ii,jj)) {
                if(dp[ii][jj]>w+1) {
                    dp[ii][jj] = w+1;
                    pq.push({w+1,{ii,jj}});
                }
            }
        }
    }
    int len = dp[st.fi][st.se];
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]>='1' && s[i][j]<='9') {
                if(dp[i][j]<=len) {
                    ans += (s[i][j]-'0');
                }
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