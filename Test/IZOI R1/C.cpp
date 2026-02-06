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
int n,t;
string s;

void solve() {
    cin >>n;
    vector adj(n, vector<int>());
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >>s;
    vector<bool> leaf(n,0);
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        bool isLeaf = 1;
        for(int v: adj[u]) {
            if(v==p) continue;
            isLeaf = 0;
            dfs(v,u);
        }
        leaf[u] = isLeaf;
    };
    dfs(0,-1);
    vector<int> ct(3,0);
    int tny = 0;
    rep(i,0,n) {
        tny += (s[i]=='?');
        if(leaf[i]) {
            if(s[i]=='?') {
                ct[2]++;
            } else {
                ct[s[i]-'0']++;
            }
        }
    }
    if(s[0]=='?') {
        int ans = max(ct[0],ct[1]) + (ct[2]/2);
        if(ct[0]==ct[1]) {
            if((tny-1-ct[2])%2) {
                ans = ct[0] + (ct[2]+1)/2;
            }
        }
        cout <<ans <<"\n";
    } else {
        int r0 = s[0]-'0';
        int ans = ct[1-r0] + ((ct[2]+1)/2);
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}