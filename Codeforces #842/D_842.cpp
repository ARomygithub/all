#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
int x[mxn+1];

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        cin >>x[i];
    }
    int ans=0;
    bool ada2=0, temp=0;
    vector<bool> vis(n+1,0);
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        int u = i;
        set<int> s;
        if(u-1>0) s.insert(u-1);
        s.insert(u+1);
        int ct=1;
        vis[u] = 1;
        while(!vis[x[u]]) {
            ct++;
            u = x[u];
            if(s.find(u)!=s.end()) temp=1;
            s.insert(u-1);
            s.insert(u+1);
            vis[u] = 1;
        }
        ans +=ct-1;
        if(ct>1) ada2=1;
    }
    if(ada2 && temp) {
        ans--;
    } else {
        ans++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}