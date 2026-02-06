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

const int mxn=2e5;
int n;
int dp[mxn];
vector<int> ed[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        int a; cin >>a;
        int start = i-a+1;
        if(start>=0) {
            ed[start].push_back(i);
        }
    }
    for(int i=n-1;i>=0;i--) {
        int ct = 0;
        int temp = 0;
        for(int edi : ed[i]) {
            temp++;
            max_self(ct, temp + (edi<n-1?dp[edi+1]:0));
        }
        if(i<n-1) {
            max_self(ct, dp[i+1]);
        }
        dp[i] = ct;
        // cout <<dp[i] <<"\n";
    }
    cout <<n-dp[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}