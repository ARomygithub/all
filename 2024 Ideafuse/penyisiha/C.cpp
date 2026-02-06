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

const int mxn=1e5;
int n,k,t;
string s[2];
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>k;
    rep(i,0,2) {
        cin >>s[i];
    }
    vector<vi> dp(2, vi(n,1e9));
    if(s[0][n-1]=='0') {
        cout <<"-1\n";
        return;
    }
    dp[0][n-1] = 0;
    priority_queue<ipii,vector<ipii>,greater<ipii>> pq;
    pq.push({0,{0,n-1}});
    while(sz(pq)) {
        // auto [d,ij] = pq.top(); pq.pop();
        // auto [i,j] = ij;
        auto d = pq.top().fi;
        auto ij = pq.top().se; pq.pop();
        auto i = ij.fi;
        auto j = ij.se;
        if(dp[i][j]<d) continue;
        if(j+1<n && s[i][j+1]=='1') {
            if(dp[i][j+1]>d+1) {
                dp[i][j+1] = d+1;
                pq.push({d+1,{i,j+1}});
            }
        }
        if(j>0 && s[i][j-1]=='1') {
            if(dp[i][j-1]>d+1) {
                dp[i][j-1] = d+1;
                pq.push({d+1,{i,j-1}});
            }
        }
        if(j-k>=0 && s[1-i][j-k]=='1') {
            if(dp[1-i][j-k]>d+1) {
                dp[1-i][j-k] = d+1;
                pq.push({d+1,{1-i,j-k}});
            }
        }
    }
    int ans = min(dp[0][0],dp[1][0]);
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
    cin >>t;
    rep(i,1,t+1) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}