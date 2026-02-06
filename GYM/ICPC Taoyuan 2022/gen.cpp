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

const int mxn=1e5;
int n;

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
    int n = code.size() + 2;
    vector<int> degree(n, 1);
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
    edges.emplace_back(leaf, n-1);
    return edges;
}

int rand(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(atoi(argv[1])); //atoi convert string to int
    int n = rand(7,1000);
    vector<int> code(n-2);
    for(int i=0;i<n-2;i++) {
        code[i] = rand(0, n-1);
    }
    vector<pair<int,int>> edges = pruefer_decode(code);
    vector adj(n,vi());
    for(auto [u,v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi a;
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        a.push_back(u);
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs(v,u);
            a.push_back(u);
        }
    };
    dfs(0,-1);
    int l= rand(0,sz(a)-1);
    int r = rand(l,sz(a)-1);
    cout <<"1\n";
    cout <<n <<"\n";
    rep(i,0,sz(a)) {
        if(i>=l && i<=r) {
            cout <<0 <<" \n"[i==sz(a)-1];
        } else {
            cout <<a[i]+1 <<" \n"[i==sz(a)-1];
        }
    }
    return 0;    
}