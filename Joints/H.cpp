#include <bits/stdc++.h>
using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}

#define fast_function \
  __attribute__((__optimize__("O3, unroll-loops"))) \
  __attribute__((__target__("avx, avx2, sse, sse2, sse3, sse4, popcnt, fma")))
/** END OF DESPERATE OPTIMIZATION **/

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5, mxm=5e3;
int n,m;
int d[mxn], anc[mxn][18];
vector<pii> adj[mxn];
ll dist[mxn];

void dfs(int a=0, int p=-1) {
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(auto [w,b] : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dist[b] = dist[a]+w;
        dfs(b,a);
    }
}

int lca(int x, int k) {
    if(d[x]<d[k]) swap(x,k);
    for(int i=17;~i;i--) {
        if(d[x]-(1<<i)>=d[k]) x =anc[x][i];
    }
    if(x==k) return x;
    for(int i=17;~i;i--) {
        if(anc[x][i]^anc[k][i]) {
            x = anc[x][i]; k=anc[k][i];
        }
    }
    return anc[x][0];
}

ll distuv(int u, int v) {
    return dist[u]+dist[v]-dist[lca(u,v)]*2;
}

void solve() {
    in(n); in(m);
    for(int i=1;i<n;i++) {
        int u,v, w; in(u); in(v); in(w); u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    d[0] = 0;
    dist[0] = 0;
    vector<int> player(m);
    set<int> s;
    // priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<m;i++) {
        in(player[i]); player[i]--;
        s.insert(player[i]);
    }
    dfs();
    ll ans= 1e18;
    for(int i=0;i<m;i++) {
        ll temp = 0;
        for(int j=0;j<m;j++) {
            if(player[i]==player[j]) continue;
            temp += distuv(player[i],player[j]);
        }
        min_self(ans, temp);
    }
    // assert(ans!=1e18);
    // cout <<ans <<"\n";
    out(ans, '\n');
}

int main() {
    solve();
}