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

const int mxn=3e5;
int n;
int a[mxn+1], apf[mxn+1];
vector<int> pf;

void solve() {
    cin >>n;
    int s,t;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    cin >>s >>t;
    vector<bool> vis(sz(pf),0);
    vector<vector<int>> v(sz(pf));
    for(int i=1;i<=n;i++) {
        int last=-1;
        int u = a[i];
        while(u>1) {
            while(u>1 && apf[u]==last) {
                u /=pf[apf[u]];
            }
            if(u==1) break;
            v[apf[u]].push_back(i);
            last = apf[u];
            u /=pf[apf[u]];
        }
    }
    // vector<int> dp(n+1,1e9);
    // dp[s] = 0;
    vector<pii> par(sz(pf),{-1,-1});
    queue<pii> q;
    q.push({s,-1});
    if(s==t) {
        cout <<"1\n";
        cout <<s <<"\n";
        return;
    }
    while(sz(q)) {
        auto [ui,pp] = q.front(); q.pop();
        int u = a[ui];
        int last=-1;
        while(u>1) {
            while(u>1 && apf[u]==last) {
                u /=pf[apf[u]];
            }
            if(u==1) break;
            if(!vis[apf[u]]) {
                vis[apf[u]] = 1;
                par[apf[u]] = {ui,pp};
                for(auto vi: v[apf[u]]) {
                    if(vi!=ui) q.push({vi,apf[u]});
                    if(vi==t) {
                        vector<int> ans;
                        ans.push_back(vi);
                        int x = apf[u];
                        do {
                            ans.push_back(par[x].fi);
                            x = par[x].se;
                        } while(x!=-1);
                        cout <<sz(ans) <<"\n";
                        for(int i=sz(ans)-1;i>=0;i--) {
                            if(i==sz(ans)-1) {
                                cout <<ans[i];
                            } else {
                                cout <<" " <<ans[i];
                            }
                        }
                        cout <<"\n";
                        return;
                    }
                }
            }
            last = apf[u];
            u /=pf[apf[u]];
        }        
    }
    cout <<"-1\n";
}

void init() {
    vector<bool> comp(mxn+1,0);
    for(int i=2;i<=mxn;i++) {
        if(!comp[i]) {
            pf.push_back(i);
            apf[i] = sz(pf)-1;
        }
        for(auto pfi : pf) {
            if(1ll*i*pfi>mxn) break;
            comp[i*pfi]=1;
            apf[i*pfi] = min(apf[i],apf[pfi]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}