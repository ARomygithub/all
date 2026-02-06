#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
const ll mod = 998244353;
int n,t;
ll iv[mxn+1];
int fp[mxn+1];
using ipii = pair<int,pii>;

void init() {
    iv[1] = 1;
    rep(i,2,mxn+1) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    vector<bool> iscomp(mxn+1,0);
    rep(i,2,mxn+1) {
        if(!iscomp[i]) {
            fp[i] = i;
            for(ll j = 1ll*i*i;j<=mxn;j+=i) {
                if(fp[j]==0) {
                    fp[j] = i;
                } else {
                    min_self(fp[j],i);
                }
                iscomp[j] = 1;
            }
        }
        // cout <<i <<" " <<fp[i] <<endl;
    }
}

void solve() {
    cin >>n;
    vector adj(n, vector<ipii>());
    rep(i,1,n) {
        int u,v,x,y; cin >>u >>v >>x >>y; u--,v--;
        adj[u].push_back({v,{y,x}});
        adj[v].push_back({u,{x,y}});
    }
    function<void(int,int)> dfs;
    vi ctp(n+1,0), ctq(n+1,0);
    vi deno(n+1,0);
    ll ans = 0;
    vector<ll> val(n,1);
    auto ad = [&](int x) -> void {
        if(ctq[x]>0) {
            ctq[x]--;
        } else {
            ctp[x]++;
        }
    };
    auto er = [&](int y) -> void {
        if(ctp[y]>0) {
            ctp[y]--;
        } else {
            ctq[y]++;
        }
        max_self(deno[y],ctq[y]);
    };
    dfs = [&](int u, int p) -> void {
        ans = (ans + val[u])%mod;
        for(auto [v, xy]: adj[u]) {
            if(v==p) continue;
            auto [x,y] = xy;
            val[v] = val[u]*x%mod;
            val[v] = val[v]*iv[y]%mod;
            int uu = x;
            while(uu>1) {
                ad(fp[uu]);
                uu /= fp[uu];
            }
            uu = y;
            while(uu>1) {
                er(fp[uu]);
                uu /= fp[uu];
            }
            dfs(v,u);
            uu = y;
            while(uu>1) {
                ad(fp[uu]);
                uu /= fp[uu];
            }            
            uu = x;
            while(uu>1) {
                er(fp[uu]);
                uu /= fp[uu];
            }
        }
    };
    dfs(0,-1);
    rep(i,2,n+1) {
        rep(j,0,deno[i]) {
            ans = ans*i%mod;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}