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

const int mxn=3e5;
int n,m;
set<int> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    map<set<int>,int> mp;
    int id=0;
    vector<int> kl(n);
    rep(i,0,n) {
        set<int> temp;
        temp.insert(i);
        for(int v: adj[i]) {
            temp.insert(v);
        }
        if(!mp.count(temp)) {
            kl[i] = id;
            mp[temp] = id++;
        } else {
            kl[i] = mp[temp];
        }
    }
    vector<int> x(n,0);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    x[0] = 1e6;
    bool ok=1;
    pq.push({x[0],0});
    vector<int> pos(n,0);
    map<int,int> klx;
    while(sz(pq) && ok) {
        auto [xi,u] = pq.top(); pq.pop();
        if(pos[u]==0) {
            set<int> skl;
            skl.insert(kl[u]);
            for(int v: adj[u]) {
                skl.insert(kl[v]);
            }
            if(sz(skl)>3) {
                ok=0;
                break;
            } else {
                klx[kl[u]] = xi;
                skl.erase(kl[u]);
                vector<int> sx = {xi-1,xi+1};
                int i=0;
                for(auto it=skl.begin();it!=skl.end();it++,i++) {
                    klx[*it] = sx[i];
                }
                for(int v: adj[u]) {
                    x[v] = klx[kl[v]];
                    if(skl.find(kl[v])!=skl.end()) {
                        pos[v] = x[v]-xi;
                        pq.push({x[v],v});
                        skl.erase(kl[v]);
                    }
                }
            }
        } else {
            set<int> skl;
            skl.insert(kl[u]);
            for(int v: adj[u]) {
                skl.insert(kl[v]);
            }
            if(sz(skl)>3) {
                ok = 0;
                break;
            } else {
                vector<int> delet;
                for(int skli: skl) {
                    if(klx.count(skli)) {
                        if(abs(klx[skli]-x[u])>1) {
                            ok = 0;
                            break;
                        } else {
                            delet.push_back(skli);
                        }
                    }
                }
                if(!ok) break;
                for(auto deleti: delet) {
                    skl.erase(deleti);
                }
                if(sz(skl)>0) {
                    int klnxt = (*skl.begin());
                    klx[klnxt] = xi+pos[u];
                    for(int v: adj[u]) {
                        if(kl[v] == klnxt) {
                            x[v] = klx[klnxt];
                            if(skl.find(klnxt)!=skl.end()) {
                                pos[v] = pos[u];
                                pq.push({x[v],v});
                                skl.erase(klnxt);
                            }
                        }
                    }
                }
            }
        }
    }
    if(!ok) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
        rep(i,0,n) {
            cout <<x[i] <<" \n"[i==n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}