#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5;
int n, m, p[mxn];
vector<int> ans, adj[mxn];

int main() {
    cin >>n >>m;
    for(int i=0; i<m; i++) {
        int a,b;
        cin >>a >>b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> qu;
    memset(p,-1,sizeof(p));
    for(int i=0; i<n; i++) {
        if(p[i]<0) {
            qu.push(i);
            p[i]=0;
            while(!qu.empty()) {
            int u=qu.front();
            qu.pop();
            for(int t : adj[u]) {
                if(p[t]<0) {
                    p[t]=p[u]^1;
                    qu.push(t);
                }
                else {
                    if(!p[t]^p[u]) {
                        cout <<"IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout <<p[i]+1 <<" ";
    }
}
