#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2500;
int n,m, p[mxn];
vector<ar<ll,2>> adj[mxn];
vector<int> adj2[mxn];
ll d[mxn];
bool vis[mxn], vis2[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >>a >>b >>c; --a, --b;
        adj[a].push_back({c,b});
        adj2[b].push_back(a);
    }
    for(int i=0;i<5*n;i++) {
        for(int j=0;j<n;j++) {
            for(ar<ll,2> a: adj[j]) {
                if(d[j]+a[0]<d[a[1]]) {
                    d[a[1]]=d[j]+a[0];
                    p[a[1]]=j;
                    if(i==n-1) {
                        cout <<"YES\n";
                        while(!vis[j]) {
                            vis[j]=1;
                            j=p[j];
                        }
                        int u=j;
                        vector<int> ans;
                        ans.push_back(u);
                        u=p[u];
                        while(u^j) {
                            ans.push_back(u);
                            u=p[u];
                        }
                        ans.push_back(u);
                        reverse(ans.begin(),ans.end());
                        for(int a: ans)
                            cout <<a+1 <<" ";
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "NO";
}   