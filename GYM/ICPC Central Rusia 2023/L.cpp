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
const int di[][6] = {{-1,-1,0,0,1,1},{-1,-1,0,0,1,1}}, dj[][6] = {{-1,0,-1,1,-1,0},{0,1,-1,1,0,1}};
int n,m;
string s[mxn];
using piii=pair<int,pii>;

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector dp(n, vi(m,1e9));
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    rep(j,0,m) {
        int i = 0;
        dp[i][j] = s[i][j]=='.';
        pq.push({dp[i][j],{i,j}});
    }
    while(sz(pq)) {
        auto [d,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        if(dp[i][j]<d) continue;
        if(i==n-1) continue;
        int b= i%2;
        rep(k,0,6) {
            int ii = i+di[b][k], jj=j+dj[b][k];
            if(e(ii,jj)) {
                int cur = d+(s[ii][jj]=='.');
                if(dp[ii][jj] > cur) {
                    dp[ii][jj] = cur;
                    pq.push({cur,{ii,jj}});
                }
            }
        }
    }
    int ans = 1e9;
    rep(j,0,m) {
        min_self(ans, dp[n-1][j]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}