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

const int mxn=2e5,mxm=20;
int n,m;
pii a[mxn];
int b[mxm];
int dp[1<<mxm];

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>a[i].fi;
        a[i].se = i+1;
    }
    for(int j=0;j<m;j++) {
        cin >>b[j];
    }
    sort(a,a+n,greater<pii>());
    vector<vector<int>> nxt(n,vector<int>(m,1e9));
    for(int j=0;j<m;j++) {
        vector<int> v(n);
        for(int i=1;i<=n;i++) {
            v[n-i] = (b[j]+i-1)/i;
        }
        for(int i=n-1;i>=0;i--) {
            auto it = upper_bound(v.begin(),v.end(),a[i].fi);
            if(it!=v.begin()) {
                it--;
                int ct = n-(it-v.begin());
                if(i-ct+1>=0) {
                    min_self(nxt[i-ct+1][j],ct);
                }
            }
        }
    }
    for(int i=1;i<(1<<m);i++) {
        dp[i] = 1e9;
        for(int j=0;j<m;j++) {
            if((i>>j)&1) {
                int last = dp[i^(1<<j)];
                if(last<n && nxt[last][j]+last<=n) {
                    min_self(dp[i], nxt[last][j]+last);
                }
            }
        }
    }
    if(dp[(1<<m)-1]==1e9) {
        cout <<"NO\n";
        return;
    }
    cout <<"YES\n";
    vector<vector<int>> ans(m);
    int u=(1<<m)-1;
    // for(int i=dp[u];i<n;i++) {
    //     ans[0].push_back(i);
    // }
    while(u!=0) {
        for(int i=0;i<m;i++) {
            if((u>>i)&1 && (dp[u^(1<<i)]<n)) {
                int last = dp[u^(1<<i)];
                if(last+nxt[last][i]==dp[u]) {
                    for(int j=last;j<dp[u];j++) {
                        ans[i].push_back(a[j].se);
                    }
                    u = u^(1<<i);
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;i++) {
        cout <<sz(ans[i]) <<" \n"[sz(ans[i])==0];
        for(int j=0;j<sz(ans[i]);j++) {
            cout <<ans[i][j] <<" \n"[j==sz(ans[i])-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}