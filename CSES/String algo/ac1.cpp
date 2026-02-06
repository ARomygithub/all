#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=5e3, mxm=1e6, mod=1e9+7;
int n,k, dp[mxn+1];
string s[mxm], t;

struct {
    int c[mxm+1][26], d[mxm+1][26], sl[mxm+1], ol[mxm+1], de[mxm+1], m=1;
    void ins(string s) {
        int u=0;
        for(char a: s) {
            if(!c[u][a-'a']) c[u][a-'a']=m++;
            u = c[u][a-'a'];
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
    cin >>t >>k;
    n =t.size();
    dp[0]=1;
    for(int i=0;i<k;i++) {
        cin >>s[i]; ac.ins(s[i]);
    }
    ac.ac();
    int u=0;
    for(int i=1;i<=n;i++) {
        u= ac.d[u][t[i-1]-'a'];
        int v=ac.ol[u];
        while(v) {
            dp[i] =(dp[i]+dp[i-ac.de[v]])%mod;
            v=ac.ol[ac.sl[v]];
        }
    }
    cout <<dp[n];
}
