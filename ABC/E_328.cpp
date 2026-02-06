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

const int mxn=8;
int n,m;
ll k, dist[mxn][mxn];
ll ans=1e18;

vector<pii> pruefer_decode(vector<int> const& code) {
    int nn = code.size() + 2;
    vector<int> degree(nn, 1);
    for (int i : code)
        degree[i]++;

    int ptr = 0;
    while (degree[ptr] != 1)
        ptr++;
    int leaf = ptr;

    vector<pair<int, int>> edges;
    for (int v : code) {
        edges.emplace_back(leaf, v);
        if (--degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, nn-1);
    return edges;
}

void dfs(int pos, vector<int>& code) {
    rep(i,0,n) {
        code[pos] = i;
        if(pos==n-3) {
            vector<pii> edges = pruefer_decode(code);
            ll temp=0;
            bool flag=1;
            for(auto [u,v]: edges) {
                if(dist[u][v]==-1) {
                    flag=0;
                    break;
                } else {
                    temp = (temp+dist[u][v])%k;
                }
            }
            if(flag) {
                min_self(ans,temp);
            }
        } else {
            dfs(pos+1,code);
        }
    }
}

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        rep(j,0,n) {
            dist[i][j] = -1;
        }
    }
    rep(i,0,m) {
        int u,v; ll w; cin >>u >>v >>w;
        u--,v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    if(n==2) {
        cout <<(dist[0][1]%k) <<"\n";
        return;
    }
    vector<int> code(n-2);
    dfs(0, code);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}