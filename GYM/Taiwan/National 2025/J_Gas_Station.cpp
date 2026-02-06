#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<ll,ll> pii;

void solve(){
    ll N,K; cin>>N>>K;

    vector<vector<pii>> g(N+1);
    ll mn = 0;
    for (int e=0;e<N-1;e++){
        ll u,v,w; cin>>u>>v>>w;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
        mn = max(mn, w);
    }

    auto check=[&](ll X){
        int cnt = 0;
        function<ll(int,int)> dfs=[&](int u, int p){
            ll r1,r2; r1=r2=0;
            
            for (auto [v,w] : g[u]){
                if (v == p){continue;}
                ll x = dfs(v,u) + w;
                if (x > X){
                    r2 = max(r2, w);
                    ++cnt;
                }else{
                    r2 = max(r2, x);
                }
                if (r1 < r2){swap(r1,r2);}
            }   
            if (r1+r2 > X){
                ++cnt;
                return 0ll;
            }

            if (u == 0 && r1+r2 > X){
                ++cnt;
            }

            return r1;
        };

        dfs(1,0);
        if (cnt <= K){
            return 1;
        }else{
            return 0;
        }
    };

    ll l,r,mid;
    l=mn;r=1e18;
    while(l<r){
        mid = (l+r)>>1;
        
        if (check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }

    cout<<l;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}