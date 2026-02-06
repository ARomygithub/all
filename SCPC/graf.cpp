#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=100;
int n,m,a,b, x,y;
vector<ar<int,2>> adj[mxn];

void solve() {
    cin >>n >>m >>a >>b;
    for(int i=0;i<m;i++) {
        int p,q,r,s; cin >>p >>q >>r >>s; p--,q--;
        adj[p].push_back({a*r+b*s,q});
        adj[q].push_back({a*r+b*s,p});
    }
    cin >>x >>y; x--, y--;
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    pq.push({0,x});
    vector<int> d(n,1e9);
    d[x]=0;
    while(pq.size()) {
        ar<int,2> u=pq.top(); pq.pop();
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
    cout <<d[y] <<"\n";
    for(int i=0;i<mxn;i++) adj[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    int t; cin >>t;
    while(t--) {
        solve();
    }
}
