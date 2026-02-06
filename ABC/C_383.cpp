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
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
int n,m,d;
string s[mxn];
using ipii = pair<int,pii>;

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]!='#';
}

void solve() {
    cin >>n >>m >>d;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector dp(n, vi(m,1e9));
    priority_queue<ipii,vector<ipii>,greater<ipii>> pq;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='H') {
                dp[i][j] = 0;
                pq.push({0,{i,j}});
            }
        }
    }
    while(sz(pq)) {
        auto [w,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        if(dp[i][j]<w) continue;
        rep(k,0,4) {
            int ii = i+di[k], jj=j+dj[k];
            if(e(ii,jj) && dp[ii][jj]>w+1) {
                dp[ii][jj] = w+1;
                pq.push({w+1,{ii,jj}});
            }
        }
    }
    int ct = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            ct += (dp[i][j]<=d);
        }
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}