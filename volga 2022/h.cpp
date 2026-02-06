#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int mxn = 2e3;
int n,m;
int p[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>p[i];
    }
    vi in(n,0);
    vector adj(n, vi());
    rep(i,0,m) {
        int a,b; cin >>a >>b; a--,b--;
        adj[b].push_back(a);
        in[a]++;
    }
    vi ans(n,-1);
    vi vp(n);
    iota(all(vp),0);
    sort(all(vp), [&](int i, int j) -> bool {
        return p[i]<p[j];
    });
    rep(u,0,n) {
        queue<int> vld;
        int id = n;
        vi ini(all(in));
        vi ct(n,0);
        int ip = n-1;
        while(ip>=0 && p[vp[ip]] >= id) {
            if(vp[ip]!=u) ct[vp[ip]]++;
            ip--;
        }
        rep(i,0,n) {
            if(i==u) continue;
            if(ini[i]==0) {
                ct[i]++;
                if(ct[i]==2) {
                    vld.push(i);
                }
            }
        }
        while(sz(vld)) {
            auto v = vld.front(); vld.pop();
            id--;
            while(ip>=0 && p[vp[ip]]>=id) {
                if(vp[ip]!=u) ct[vp[ip]]++;
                if(ct[vp[ip]]==2) {
                    vld.push(vp[ip]);
                }                
                ip--;
            }
            for(auto& v2: adj[v]) {
                if(v2==u) continue;
                ini[v2]--;
                if(ini[v2]==0) {
                    ct[v2]++;
                    if(ct[v2]==2) {
                        vld.push(v2);
                    }
                }
            }
        }
        ans[u] = id;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}