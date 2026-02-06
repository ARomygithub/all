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

const int mxn=1e5;
int n,m,x;
int a[10],b[mxn];
bool dp[mxn+1];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    cin >>m;
    for(int i=0;i<m;i++) {
        cin >>b[i];
    }
    cin >>x;
    dp[0]=1;
    for(int i=1,j=0;i<=x;i++) {
        if(j<m && b[j]==i) {
            dp[i] = 0;
            j++;
            continue;
        }
        bool flag=0;
        for(int k=0;k<n;k++) {
            if(a[k]>i) break;
            flag = flag||dp[i-a[k]];
        }
        dp[i] = flag;
    }
    cout <<(dp[x]?"Yes\n":"No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}