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

const int mxn=1e4;
int n,m;
string s1,s2;
int dp[mxn][mxn];

void solve() {
    getline(cin, s1);
    getline(cin, s2);
    n = s1.length();
    m = s2.length();
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            int temp1 = 1 + (i+1<n?dp[i+1][j]:m-j);
            int temp2 = 1 + (j+1<m?dp[i][j+1]:n-i);
            dp[i][j] = min(temp1, temp2);
            int temp3 = (s1[i]!=s2[j]);
            if(i+1<n && j+1<m) {
                temp3 +=dp[i+1][j+1];
            } else if(i+1<n) {
                temp3 +=n-i-1;
            } else if(j+1<m) {
                temp3 +=m-j-1;
            }
            min_self(dp[i][j], temp3);
        }
    }
    cout <<dp[0][0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}