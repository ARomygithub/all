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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;
vector<int> adj[mxn];
int q[mxn];
bool used[mxn];

void solve() {
    cin >>n >>m;
    map<pii,int> mp;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}] = 1;
        mp[{v,u}] = 1;
    }
    if(n<=6) {
        vector<pii> v;
        rep(i,0,n) {
            rep(j,i+1,n) {
                v.push_back({i,j});
            }
        }
        bool found = 0;
        rep(i,0,(1<<sz(v))) {
            vector<int> ct(n,0);
            int mm=0;
            bool ok = 1;
            rep(j,0,sz(v)) {
                if((i>>j)&1) {
                    mm++;
                    int uu = v[j].fi;
                    int uv = v[j].se;
                    if(mp[{uu,uv}]) {
                        ok = 0;
                        break;
                    }
                    ct[uu]++, ct[uv]++;
                }
            }
            if(mm!=m) ok=0;
            rep(j,0,n) {
                if(ct[j]>2) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                found = 1;
                rep(j,0,sz(v)) {
                    if((i>>j)&1) {
                        cout <<v[j].fi+1 <<" " <<v[j].se+1 <<"\n";
                    }
                }
                break;
            }
        }
        if(!found) {
            cout <<"-1\n";
        }
        return;
    }
    int l = 0, r= 0;
    rep(i,0,n) {
        if(!used[i]) {
            used[i] = 1;
            q[r++] = i;
            while(r>l) {
                int v = q[l++];
                rep(j,0,sz(adj[v])) {
                    if(!used[adj[v][j]]) {
                        used[adj[v][j]] = 1;
                        q[r++] = adj[v][j];
                    }
                }
            }
        }
    }
    rep(i,0,m) {
        cout <<q[i]+1 <<" " <<q[(i+3)%n] +1 <<"\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}