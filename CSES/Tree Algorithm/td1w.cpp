#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n;
int ml1[mxn], ans[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        ml1[a]=max(ml1[a],ml1[b]+1);
    }
}

void dfs2(int a=0, int p=-1, int pd=0) {
    ans[a] =max(ml1[a],pd);
    vector<ar<int,2>> w {{pd,-1}};
    for(int b : adj[a]) {
        if(b==p) continue;
        w.push_back({ml1[b]+1,b});
    }
    w.push_back({0,-1});
    sort(w.begin(),w.end(),greater<ar<int,2>>());
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs2(b,a,w[0][1]==b?w[1][0]+1:w[0][0]+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=1;i<n;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    dfs2();
    for(int i=0;i<n;i++) {
        cout <<ans[i] <<" ";
    }
}
