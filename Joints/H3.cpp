#include <bits/stdc++.h>
using namespace std;

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
int ct[mxn], ct2[mxn];
vector<pll> adj[mxn];
vector<pll> adj2[mxm];
ll temp=0;
int idx=0;
map<int, int> mp;

void dfs(int a=0, int p=-1, ll wp=0, int last=0) {
    for(auto [w,b] : adj[a]) {
        if(b==p) continue;
        temp +=(wp+w)*ct[b];
        if(ct[b]>0) {
            mp[b] = idx;
            ct2[idx] = ct[b];
            int mpb = idx;
            idx++;
            adj2[last].push_back({wp+w,mpb});
            adj2[mpb].push_back({wp+w,last});
            dfs(b,a, wp+w, mpb);
        } else {
            dfs(b,a, wp+w, last);
        }
    }
}

void dfs2(int a=0, int p=-1, ll wp=0) {
    for(auto [w,b]: adj2[a]) {
        if(b==p) continue;
        // temp += (wp+w)*ct2[b];
        temp += (wp+w);
        dfs2(b,a,wp+w);
    }
}

void solve() {
    cin >>n >>m;
    for(int i=1;i<n;i++) {
        ll u,v, w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    vector<int> player(m);
    for(int i=0;i<m;i++) {
        cin >>player[i]; player[i]--;
        ct[player[i]]++;
    }
    ll ans= 1e18;
    mp[player[0]] = idx;
    ct2[idx] = ct[player[0]];
    idx++;
    dfs(player[0]);
    // cout <<temp <<"\n";
    min_self(ans,temp);
    for(int i=0;i<m;i++) {
        temp = 0;
        dfs2(mp[player[i]]);
        // cout << temp <<"\n";
        min_self(ans, temp);
    }
    // assert(ans!=1e18);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}