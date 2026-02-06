#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=50,mxa=1e4;
int n,x;
bool dp[mxa+1];
pii ab[mxn];

void solve() {
    cin >>n >>x;
    for(int i=0;i<n;i++) {
        cin >>ab[i].fi >>ab[i].se;
    }
    dp[0] = 1;
    for(int i=0;i<n;i++) {
        for(int j=x;j>0;j--) {
            for(int k=0;k<=ab[i].se;k++) {
                if(j-k*ab[i].fi<0) break;
                dp[j] |=dp[j-k*ab[i].fi];
            }
        }
    }
    if(dp[x]) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}