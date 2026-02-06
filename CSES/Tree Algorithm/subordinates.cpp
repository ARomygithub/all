#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n, s[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    for(int b : adj[a]) {
        dfs(b,a);
        s[a] +=s[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=1;i<n;i++) {
        int p; cin >>p; p--;
        adj[p].push_back(i);
    }
    dfs();
    for(int i=0;i<n;i++) {
        cout <<s[i]-1 <<" ";
    }
}
