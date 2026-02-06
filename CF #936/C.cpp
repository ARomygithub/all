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
int n,k,t;

void solve() {
    cin >>n >>k;
    vector adj(n, vector<int>());
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l=1,r=n/(k+1);
    int ans=1;
    int potong = 0;
    function<int(int,int,int)> dfs;
    dfs = [&](int u, int p, int midi) -> int {
        int ctu= 1;        
        for(int v: adj[u]) {
            if(v==p) continue;
            ctu += dfs(v,u,midi);
        }
        if(ctu>=midi) {
            potong++;
            ctu = 0;
        }
        return ctu;
    };
    while(l<=r) {
        int mid = (l+r)/2;
        potong = 0;
        dfs(0,-1,mid);
        // cout <<mid <<" " <<potong <<"\n";
        if(potong>=k+1) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout <<ans <<"\n";
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