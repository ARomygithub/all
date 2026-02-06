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

const int mxn=1e2;
int n;
int d[mxn];
int l1,c1,k1,l2,c2,k2;

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>d[i];
    }
    cin >>l1 >>c1 >>k1;
    cin >>l2 >>c2 >>k2;
    vector<vector<int>> butuh2(n,vector<int>(k1+1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<=k1;j++) {
            butuh2[i][j] = max(0, (d[i]-l1*j+l2-1)/l2);
        }
    }
    vector<int> dp(k1+1,0);
    for(int i=0;i<n;i++) {
        vector<int> dp_new(k1+1,1e9);
        for(int j=0;j<=k1;j++) {
            for(int k=0;k<=k1-j;k++) {
                // if(k+j>k1) continue;
                min_self(dp_new[k+j], dp[k]+butuh2[i][j]);
            }
        }
        dp.swap(dp_new);
    }
    ll ans=1e18;
    for(int i=0;i<=k1;i++) {
        if(dp[i]<1e9 && dp[i]<=k2) {
            min_self(ans, 1ll*i*c1+1ll*dp[i]*c2);
        }
    }
    if(ans==1e18) {
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