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

const int mxn=300;
int n,k;
string s;
int dp[mxn][mxn];
bool vis[mxn][mxn];

int getDp(int l, int r) {
    if(l>r) return 0;
    if(vis[l][r]) return dp[l][r];
    if(s[l]=='o') {
        min_self(dp[l][r],r-l+1);
        for(int i=l+1;i<=r;i++) {
            int temp = getDp(l+1,i-1);
            if(temp==0 && s[i]=='f') {
                min_self(dp[l][r],max(getDp(i+1,r)-k,0));
            }
            min_self(dp[l][r],i-l+getDp(i,r));
        }
    } else {
        min_self(dp[l][r],1+getDp(l+1,r));
        // for(int i=l+1;i<=r;i++) {
        //     min_self(dp[l][r],getDp(l,i-1)+getDp(i,r));
        // }
    }
    vis[l][r] = 1;
    return dp[l][r];
}

void solve() {
    cin >>s;
    cin >>k;
    n = s.length();
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            dp[i][j] = 1e9;
        }
    }
    int ans = getDp(0,n-1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}