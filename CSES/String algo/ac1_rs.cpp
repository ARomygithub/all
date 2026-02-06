#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1000, mxm=100, mod=1e9+7;
int n, dp[2][mxn+1][mxm+1];
string s;

struct {
    int c[mxm+1][26], d[mxm+1][26], sl[mxm+1], ol[mxm+1], de[mxm+1], m=1;
    void ins(string s) {
        int u=0;
        for(char a: s) {
            if(!c[u][a-'A']) c[u][a-'A']=m++;
            u = c[u][a-'A'];
        }
        ol[u]=u;
    }
    void ac() {
        queue<int> qu;
        qu.push(0);
        while(qu.size()) {
            int u=qu.front(); qu.pop();
            for(int i=0;i<26;i++) {
                if(c[u][i]) {
                    int v=c[u][i];
                    de[v] = de[u]+1;
                    sl[v] =d[sl[u]][i];
                    if(!ol[v]) ol[v]=ol[sl[v]];
                    d[u][i] =v;
                    qu.push(v);
                } else {
                    d[u][i] =d[sl[u]][i];
                }
            }
        }
    }
} ac;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n >>s;
    ac.ins(s);
    ac.ac();
    dp[0][0][0]=1;
    for(int k : {0,1}) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<=s.size();j++) {
                for(int l=0;l<26;l++) {
                    int j2=ac.d[j][l], k2=k||(j2==s.size());
                    dp[k2][i+1][j2] = (dp[k2][i+1][j2]+dp[k][i][j])%mod;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=s.size();i++) {
        ans = (ans+dp[1][n][i])%mod;
    }
    cout <<ans;
}
