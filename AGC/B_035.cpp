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
vector<pii> adj[mxn], adj2[mxn];

void solve() {
    cin >>n >>m;
    vector<pii> e(m);
    vector<bool> sign(m,0);
    vector<bool> val(n,0);
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(u>v) swap(u,v);
        adj[u].push_back({v,i});
        adj2[v].push_back({u,i});
        val[u] =val[u]^1;
        e[i] = {u,v};
    }
    if(m%2) {
        cout <<"-1\n";
        return;
    }
    vector<int> nord;
    vector<int> ord(n,-1);
    queue<int> q;
    ord[0] = 0;
    nord.push_back(0);
    q.push(0);
    while(sz(q)) {
        int u = q.front(); q.pop();
        for(auto [v,id]: adj[u]) {
            if(ord[v]==-1) {
                ord[v] = sz(nord);
                nord.push_back(v);
                q.push(v);
            }
        }
        for(auto [v,id]: adj2[u]) {
            if(ord[v]==-1) {
                ord[v] = sz(nord);
                nord.push_back(v);
                q.push(v);
            }
        }
    }
    per(i,n-1,0) {
        int u = nord[i];
        if(val[u]) {
            for(auto [v,id]: adj2[u]) {
                if(ord[v]<ord[u]) {
                    val[u] = val[u]^1;
                    val[v] = val[v]^1;
                    sign[id] = sign[id]^1;
                    break;
                }
            }
            if(!val[u]) continue;
            for(auto [v,id]: adj[u]) {
                if(ord[v]<ord[u]) {
                    val[u] = val[u]^1;
                    val[v] = val[v]^1;
                    sign[id] = sign[id]^1;
                    break;
                }
            }
        }
    }
    rep(i,0,m) {
        if(sign[i]) {
            cout <<e[i].se+1 <<" " <<e[i].fi+1 <<"\n";
        } else {
            cout <<e[i].fi+1 <<" " <<e[i].se+1 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}