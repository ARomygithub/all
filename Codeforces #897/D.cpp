#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,k,t;

void solve() {
    cin >>n >>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++) {
        int ai; cin >>ai; ai--;
        adj[i].push_back(ai);
    }
    vector<bool> vis(n,0);
    set<int> s;
    function<void(int,int)> dfs;
    vector<int> vd(n,-1);
    int lastD=-1, tempD;
    dfs = [&](int u, int d) -> void {
        vis[u] = 1;
        vd[u] = d;
        max_self(tempD,d);
        for(auto v : adj[u]) {
            if(!vis[v]) {
                dfs(v,d+1);
            } else {
                if(vd[v]>lastD) {
                    s.insert(vd[u]-vd[v]+1);
                }
            }
        }
    };
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i,tempD+1);
            lastD = tempD;
        }
    }
    bool flag=true;
    if(k==1) {
        for(int i=0;i<n&&flag;i++) {
            for(auto ai: adj[i]) {
                flag &= ai==i;
            }
        }
    } else {
        if(sz(s)) {
            for(auto si : s) {
                if(si!=k) {
                    flag = false;
                }
            }
        }
    }
    if(flag) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
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