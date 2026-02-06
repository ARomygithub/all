#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn=1e5;
int n,m;
ll d[mxn];
vector<ar<ll,2>> adj[mxn];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        ll a,b,c;
        cin >>a >>b >>c; --a, --b;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    pq.push({0,0});
    memset(d,0x3f,sizeof(d));
    d[0]=0;
    while(pq.size()) {
        ar<ll,2> u=pq.top(); pq.pop();
        //process u
        if(u[0]>d[u[1]])
            continue;
        for(auto v : adj[u[1]]) {
            if(d[v[1]]>u[0]+v[0]) {
                d[v[1]]=u[0]+v[0];
                pq.push({d[v[1]],v[1]});
            }
        }
    }
    cout <<d[n-1];
}  