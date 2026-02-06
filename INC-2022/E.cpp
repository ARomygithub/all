#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

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
int dp[mxn];
vector<pii> adj[mxn];

const int S = 1 << 18;
const int MAX_BIT = 30;

struct node{
    int value;
    int leftChildID;
    int rightChildID;
    node() {
        
    }
    node(int v, int l, int r):
    value(v), leftChildID(l), rightChildID(r) {
        
    }
};

node pool[S];
int offset = 0;
int dt[S];

int allocate(int value) {
    pool[++offset].value = value;
    pool[offset].leftChildID = -1;
    pool[offset].rightChildID = -1;
    return offset;
}
void add(int value) {
    int id = 0;
    for (int i = MAX_BIT; i >= 0; i --) {
        int bit = (value >> i) & 1;
        if (!bit) {
            if (pool[id].leftChildID == -1) {
                pool[id].leftChildID = allocate(0);
            }
            id = pool[id].leftChildID;
        } else {
            if (pool[id].rightChildID == -1) {
                pool[id].rightChildID = allocate(0);
            }
            id = pool[id].rightChildID;
        }
        pool[id].value = 1;
    }
}
int getMatch(int x) {
    int id = 0;
    int result = 0;
    for (int i = MAX_BIT; i >= 0; i --) {
        if (pool[id].value == 0) {
            break;
        }
        int bit = (x >> i) & 1;
        if (!bit) {
            if (pool[id].rightChildID != -1) {
                result |= 1 << i;
                id = pool[id].rightChildID;
            } else {
                id = pool[id].leftChildID;
            }
        } else {
            if (pool[id].leftChildID != -1) {
                id = pool[id].leftChildID;
            } else {
                result |= 1 << i;
                id = pool[id].rightChildID;
            }
        }
    }
    return result;
}

void dfs(int u=0, int p=-1) {
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        dp[v] = dp[u]^w;
        dfs(v,u);
    }
}

int solve2(int X) {
    for (int i = 0; i < S; i ++) {
        pool[i] = node(0, -1, -1);
    }
    pool[0].value = 1;
    offset = 0;
    add(0);
    int prefix = 0, bestResult = dt[1];
    for (int i = 1; i <= n; i ++) {
        prefix ^= dt[i];
        add(prefix);
        int current = prefix ^ getMatch(X ^ prefix);
        if ((X ^ current) > (X ^ bestResult)) {
            bestResult = current;
        }
    }
    // cout <<"TES\n" <<flush;
    return bestResult;
}

void solve() {
    cin >>n;
    for(int i=1;i<n;i++) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    // cout <<"Halo\n" <<flush;
    dfs(0);
    // cout <<"abis dfs\n" <<flush;
    for(int i=1;i<=n;i++) {
        dt[i] = (i>1?dp[i-2]^dp[i-1]:dp[i-1]);
    }
    int mn = solve2((1<<29)-1);
    int mx = solve2(0);
    cout <<mn <<" " <<mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}