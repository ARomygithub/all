#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,m,k;
vector<ar<ll,2>> adj[mxn];
vector<ll> d[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m >>k;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >>a >>b >>c; --a, --b;
        adj[a].push_back({c,b});
    }
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    pq.push({0,0});
    while(pq.size()) {
        ar<ll,2> u=pq.top(); pq.pop();
        //process u
        if(d[u[1]].size()>=k)
            continue;
        d[u[1]].push_back(u[0]);
        for(auto v : adj[u[1]]) {
            pq.push({u[0]+v[0],v[1]});
        }
    }
    for(int i=0;i<k;i++) {
        cout <<d[n-1][i] <<" ";
    }
}   