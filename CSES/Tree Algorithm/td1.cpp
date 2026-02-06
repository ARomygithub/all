#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n;
int ml1[mxn][2], ml2[mxn][2];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        if(ml1[a][0]<=ml1[b][0]+1) {
            ml2[a][0] = ml1[a][0]; ml2[a][1] = ml1[a][1];
            ml1[a][0]=ml1[b][0]+1; ml1[a][1] =b;
        } else if(ml2[a][0]<=ml1[b][0]+1) {
            ml2[a][0] = ml1[b][0]+1; ml2[a][1]=b;
        }
    }
}

void dfs2(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        if(ml1[a][1]!=b) {
            if(ml1[a][0]+1>=ml1[b][0]) {
                ml2[b][0]=ml1[b][0]; ml2[b][1]=ml1[b][1];
                ml1[b][0]=ml1[a][0]+1; ml1[b][1]=a;
            } else if(ml1[a][0]+1>=ml2[b][0]){
                ml2[b][0]=ml1[a][0]+1; ml2[b][1]=a;
            }
        } else {
            if(ml2[a][0]+1>=ml1[b][0]) {
                ml2[b][0]=ml1[b][0]; ml2[b][1]=ml1[b][1];
                ml1[b][0]=ml2[a][0]+1; ml1[b][1]=a;
            } else if(ml2[a][0]+1>=ml2[b][0]){
                ml2[b][0]=ml2[a][0]; ml2[b][1]=a;
            }
        }
        dfs2(b,a);
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
        cout <<ml1[i][0] <<" ";
    }
}
