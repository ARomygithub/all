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

const int mxn=3e3;
int n,m;
string s1, s2;
string dp[2][mxn];

void solve() {
    cin >>s1;
    cin >>s2;
    n = s1.length(), m = s2.length();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s1[i]==s2[j]) {
                dp[1][j] = (i>0&&j>0?dp[0][j-1]:"")+ s1[i];
            } else {
                string a = (i>0?dp[0][j]:"");
                string b = (j>0?dp[1][j-1]:"");
                if(a.length()>b.length()) {
                    dp[1][j] = a;
                } else {
                    dp[1][j] = b;
                }
            }
        }
        swap(dp[0],dp[1]);
    }
    cout <<dp[0][m-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}