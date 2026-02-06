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

const int mxn=2e5;
int n,m;
string s;
set<int> adj[mxn];

void solve() {
    cin >>n >>m;
    cin >>s;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    set<int> st;
    rep(i,0,n) {
        st.insert(i);
    }
    vector ct(n, vector<int>(2,0));
    rep(i,0,n) {
        for(int v: adj[i]) {
            ct[i][s[v]-'A']++;
        }
    }
    function<void(int)> ers;
    ers = [&](int u) -> void {
        // cout <<u <<endl;
        set<int> toErs;
        for(int v: adj[u]) {
            if(v!=u) {
                ct[v][s[u]-'A']--;
                adj[v].erase(u);
                if(ct[v][s[u]-'A']==0) {
                    toErs.insert(v);
                }
            }
        }
        st.erase(u);
        for(int v: toErs) {
            if(st.count(v)) {
                ers(v);
            }
        }
    };
    rep(i,0,n) {
        if(ct[i][0]==0 || ct[i][1]==0) {
            if(st.count(i)) {
                ers(i);
            }
        }
    }
    if(sz(st)>0) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}