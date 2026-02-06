#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define what_is(x) cerr << #x << ": " << x << endl;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}
template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}

const int mxn = 6000;
int n;
string s;

void solve() {
    cin >>n;
    cin >>s;
    if(s[0]==')' && s[n-1]==')') {
        cout <<"Polycarp\n";
        return;
    }
    map<char,int> mp;
    mp['('] = 1;
    mp[')'] = -1;
    vector dp(n, vi(n,0));
    rep(len,1,n+1) {
        if(len==1) {
            rep(i,0,n) {
                // dp[i][i] = mp[s[i]]; 
                min_self(dp[i][i], mp[s[i]]);
            }
            continue;
        }
        rep(i,0,n-len+1) {
            int j = i+len-1;
            int le = mp[s[i]] + max((i+2<=j?dp[i+2][j]:0), (i+1<=j-1? dp[i+1][j-1]: 0));
            min_self(dp[i][j], le);
            int ri = mp[s[j]] + max( (i<=j-2? dp[i][j-2]:0), (i+1<=j-1?dp[i+1][j-1]:0));
            min_self(dp[i][j],ri);
            // what_is(i)
            // what_is(j)
            // what_is(dp[i][j])
        }
    }
    int cur = 1e9;
    if(s[0]=='(') {
        min_self(cur, max(1+ (2<=n-1?dp[2][n-1]:0), 1 + (1<=n-2?dp[1][n-2]:0)));
    }
    if(s[n-1]=='(') {
        min_self(cur, max(1 + (0<=n-3?dp[0][n-3]:0), 1 + (1<=n-2?dp[1][n-2]:0)));
    }
    if(cur>0) {
        cout <<"Polycarp\n";
    } else {
        cout <<"Monocarp\n";
    }
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}

/*
1
6
()((()


i: 0
j: 1
dp[i][j]: -1
i: 1
j: 2
dp[i][j]: -1
i: 2
j: 3
dp[i][j]: 1
i: 3
j: 4
dp[i][j]: 1
i: 4
j: 5
dp[i][j]: -1
i: 0
j: 2
dp[i][j]: 2
i: 1
j: 3
dp[i][j]: 0
i: 2
j: 4
dp[i][j]: 2
i: 3
j: 5
dp[i][j]: 0
i: 0
j: 3
dp[i][j]: 0
i: 1
j: 4
dp[i][j]: 0
i: 2
j: 5
dp[i][j]: 0
i: 0
j: 4
dp[i][j]: 3
i: 1
j: 5
dp[i][j]: 1
i: 0
j: 5
dp[i][j]: -1
Polycarp
*/