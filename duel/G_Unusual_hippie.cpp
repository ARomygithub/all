#include <bits/stdc++.h>
using namespace std; 
#define pb push_back
#define int long long
typedef pair<int,int> pii;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e6;


struct DSU {
    int n;
    vector<int> wt, par, ttl;
 
    DSU(int x){
        n = x;
        wt.assign(n, 1);
        par.resize(n);
        ttl.resize(n);

        for(int i = 0; i < n; ++i){
            par[i] = i;
        }    
    }
 
    int find(int v){
        if(par[v] == v) return v;
        return par[v] = find(par[v]);
    }
    
    int give(int u, int val){
        ttl[u] = val;
    }

    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;
 
        if(wt[u] < wt[v]) swap(u, v);
 
        par[v] = u;
        wt[u] += wt[v];
        ttl[u] = min(ttl[u], ttl[v]);
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<array<int,4>> a;
    for(int i = 0; i < n; ++i){
        int xi, yi, ti;
        cin >> xi >> yi >> ti;
        a.pb({xi, yi, ti, i});
    }

    DSU dsu(n);
    for(int i = 0; i < n; ++i){
        dsu.give(i, a[i][2]);
    }

    for(int z = 0; z < 2; ++z){
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); ++i){
            if(i + 1 < a.size() && a[i][0] == a[i + 1][0] && a[i + 1][1] - a[i][1] <= k){
                dsu.merge(a[i][3], a[i + 1][3]);
            }
            swap(a[i][0], a[i][1]);
        }
    }

    vector<int> vis(n);
    vector<int> times;
    for(int i = 0; i < n; ++i){
        if(!vis[dsu.find(i)]){
            times.pb(dsu.ttl[dsu.find(i)]);
            vis[dsu.find(i)] = 1;
        }
    }

    sort(times.begin(), times.end());
    int tm = 0, l = 0;
    int sz = times.size();
    for(int i = 0; i < sz; ++i){
        if(!times.empty()) times.pop_back();
        while(l < times.size() && times[l] <= tm){
            l++;
        }
        if(l >= times.size()){
            cout << tm << endl;
            return;
        }
        tm++;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}