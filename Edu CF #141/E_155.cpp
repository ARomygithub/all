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

const int mxn=1e2;
int n,t;
vector<int> adj[mxn];
int k=1;
int c[mxn];
set<pii> s12;

void dfs1(int u, int d, set<pii>& s12i) {
    if(d>=2) {
        max_self(k,2);
    }
    if(u!=0 && sz(adj[u])==1) {
        s12i.insert({c[u],3-c[u]});
        if(sz(s12i)>=2) {
            max_self(k,3);
            return;
        }
    }
    for(int v: adj[u]) {
        if(u==0) {
            set<pii> s120;
            c[v] = 1;
            dfs1(v, d+1, s120);
            if(k==3) return;
            if(sz(s12)==0) {
                if(sz(s120)) {
                    s12.insert(*s120.begin());
                }
            } else if(sz(s12)==1 && sz(s120)==1) {
                if((*s12.begin()).fi!=(*s120.begin()).fi) {
                    s120.clear();
                    c[v] = 2;
                    dfs1(v, d+1, s120);
                }
            }
        } else {
            c[v] = 3-c[u];
            dfs1(v, d+1, s12i);
        }
        if(k>=3) return;
    }
}

void dfs2(int u) {
    for(int v: adj[u]) {
        if(u==0) {
            c[v] = 1;
        } else {
            if(c[u]==1) {
                c[v] = 2;
            } else if(c[u]==2) {
                c[v] = 3;
            } else if(c[u]==3) {
                c[v] = 1;
            }
        }
        dfs2(v);
    }
}

void solve() {
    cin >>n;
    for(int i=1;i<=n-1;i++) {
        int p; cin >>p; p--;
        adj[p].push_back(i);
    }
    c[0] = -1;
    dfs1(0, 0, s12);
    if(k>=3) {
        c[0] = -1;
        dfs2(0);
    }
    cout <<k <<"\n";
    for(int i=1;i<=n-1;i++) {
        cout <<c[i] <<" \n"[i==n-1];
    }
    cout <<flush;
    int state; cin >>state;
    while(state!=1 && state!=-1) {
        vector<int> ct(k);
        vector<int> calon;
        for(int i=0;i<k;i++) {
            cin >>ct[i];
            if(ct[i]==1) {
                calon.push_back(i+1);
            }
        }
        if(sz(calon)==1) {
            cout <<calon[0] <<"\n";
            cout <<flush;
        } else {
            if(k==3) {
                int ans=-1;
                if(calon[0]==1 && calon[1]==2) {
                    ans = 1;
                } else if(calon[0]==2 && calon[1]==3) {
                    ans = 2;
                } else if(calon[0]==1 && calon[1]==3) {
                    ans = 3;
                }
                cout <<ans <<"\n";
                cout <<flush;
            } else {
                int ans=-1;
                if(s12.find({calon[0],calon[1]})!=s12.end()) {
                    ans = calon[0];
                } else {
                    ans = calon[1];
                }
                cout <<ans <<"\n";
                cout <<flush;
            }
        }
        cin >>state;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}