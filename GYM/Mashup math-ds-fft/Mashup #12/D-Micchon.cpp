#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>

//const int MOD = 1000000007;
const int MOD = 998244353;

struct query {
    int start, cnt;
    bool modded;
    bool operator <(query &o) {
        return start < o.start;
    }
};

vector<vector<int>> adj;
vector<vector<query>> q;
vector<bool> vis;
void mer(vector<query> &vec) {
    sort(vec.begin(),vec.end());
    vector<query> ret;
    // add continuous part
    for (int i = 0; i < vec.size();) {
        int cnt = 0;
        bool modded = 0;
        int j;
        for (j = i; j < vec.size() && (modded || vec[j].start <= vec[i].start + cnt); j++ ) {
            //cout << vec[j].start << ' ' << vec[i].start << ' ' << cnt << '\n';
            cnt += vec[j].cnt;
            if (cnt >= MOD) {
                cnt %= MOD;
                modded = 1;
            }
            modded |= vec[j].modded;
        }
        query p;
        p.start = vec[i].start;
        p.cnt = cnt;
        p.modded = modded;

        ret.push_back(p);
        i = j;
    }

    vec = ret;
}

void oput(int pos, vector<query> &vec) {
    cout << pos << " : ";
    bool fi = 1;
    cout << "{";
    for(query &p : vec) {
        if(!fi) cout << " , ";
        else fi = 0;
        cout << "(" << p.start << " , " << p.cnt << " , " << p.modded << ")";
    }
    cout << "}\n";
}

void dfs(int pos, int prev=-1) {
    if(vis[pos]) return;
    vis[pos] = 1;

    for (int &nxt: adj[pos]) {
        if(nxt == prev) continue;
        dfs(nxt);
        forn(i, q[nxt].size()) {
            if(q[nxt][i].cnt || q[nxt][i].modded) {
                q[pos].push_back(q[nxt][i]);
                q[pos].back().start++;
            }
        }
    }
    //oput(pos, q[pos]);
    mer(q[pos]);
    //oput(pos, q[pos]);
}

void solve() {
    query qu;
    qu.modded = 0;
    qu.start = 0;

    int n,m;
    cin >> n >> m;
    q = vector<vector<query>>(n, vector<query>());
    adj = vector<vector<int>>(n, vi());
    vis = vector<bool>(n, 0);

    vi out(n,0);
    forn(i,n) {
        cin >> qu.cnt;
        q[i].push_back(qu);
    }

    forn(i,m) {
        int u,v; cin >> u >> v;
        u--;v--;
        adj[v].push_back(u);
        out[u]++;
    }

    int root = -1;
    forn(i,n) {
        if(out[i] == 0) root = i;
    }

    dfs(root);

    cout << (q[root].back().start + q[root].back().cnt) % MOD << '\n';
}

int32_t main()
{
    //ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}