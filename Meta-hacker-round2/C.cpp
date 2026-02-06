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

const int mxn=1e6;
int n,t;
vector<int> adj[mxn];
set<string> kms[mxn];
set<string> s;

void dfs(int u, int p) {
    // cout <<"dfs\n" <<flush;
    vector<pii> nxt;
    map<string,int> mp;
    for(int v : adj[u]) {
        if(v==p) continue;
        set<string> ssi;
        for(string si : kms[v]) {
            ssi.insert(si);
        }
        int pi = u;
        int vv = v;
        while(sz(adj[vv])<=2) {
            int nxti = -1;
            for(int vvv : adj[vv]) {
                if(vvv==pi) continue;
                nxti = vvv;
            }   
            if(nxti!=-1) {
                pi = vv;
                vv = nxti;
                for(string si : kms[vv]) {
                    ssi.insert(si);
                }
            } else {
                break;
            }
        }
        for(string si : ssi) {
            mp[si]++;
        }
        if(sz(adj[vv])>2) {
            nxt.push_back({vv,pi});
        }
    }
    int ctc = sz(adj[u])-(p!=-1);
    set<string> toDel;
    for(string si : s) {
        if(mp[si]<ctc-1) {
            toDel.insert(si);
        }
    }
    for(string si : toDel) {
        s.erase(si);
    }
    for(auto [v,pi]: nxt) {
        dfs(v,pi);
    } 
}

void dfs2(int u, int p) {
    // cout <<"dfs\n" <<flush;
    map<string,int> mp;
    for(int v : adj[u]) {
        if(v==p) continue;
        dfs2(v,u);
        for(string si : kms[v]) {
            mp[si]++;
        }
    }
    int ctc = sz(adj[u])-(p!=-1);
    for(auto [si, val]: mp) {
        if(val==ctc) {
            kms[u].insert(si);
        }
    }
}

void solve() {
    cin >>n;
    for(int i=1;i<n;i++) {
        int pi; cin >>pi; pi--;
        adj[pi].push_back(i);
        adj[i].push_back(pi);
    }
    for(int i=0;i<n;i++) {
        int m; cin >>m;
        for(int j=0;j<m;j++) {
            string si; cin >>si;
            kms[i].insert(si);
        }
    }
    for(string si : kms[0]) {
        s.insert(si);
    }
    int pi = -1;
    int vv=0;
    dfs2(vv,pi);    
    while(sz(adj[vv])-(pi!=-1)<=1) {
        int nxti = -1;
        for(int vvv : adj[vv]) {
            if(vvv==pi) continue;
            nxti = vvv;
        }   
        if(nxti!=-1) {
            pi = vv;
            vv = nxti;
            for(string si : kms[vv]) {
                s.insert(si);
            }
        } else {
            break;
        }
    }
    dfs(vv,pi);
    cout <<sz(s) <<"\n";
    s.clear();
    for(int i=0;i<n;i++) {
        adj[i].clear();
    }
    for(int i=0;i<n;i++) {
        kms[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
        // cout <<flush;
    }
}