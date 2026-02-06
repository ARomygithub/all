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

const int mxn=3e5;
int n,m;
vector<int> adj[mxn];

void solve() {
    cin >>n >>m;
    vector<int> arr;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(u==-1) {
            arr.push_back(v);
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<int> s(n,1e9), t(n,1e9);
    s[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(s[u]<d) continue;
        for(int v: adj[u]) {
            if(d+1<s[v]) {
                s[v] = d+1;
                pq.push({s[v],v});
            }
        }
    }
    t[n-1] = 0;
    pq.push({0,n-1});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(t[u]<d) continue;
        for(int v: adj[u]) {
            if(d+1<t[v]) {
                t[v] = d+1;
                pq.push({t[v],v});
            }
        }
    }
    vector<int> ans(n,s[n-1]);
    int si = 1e9, ti=1e9, ansi=1e9;
    for(int v: arr) {
        min_self(si, s[v]);
        min_self(ti, t[v]);
    }
    ansi = si+ti+2;
    rep(i,0,n) {
        int temp = min(s[i] + ti +1, si + t[i] + 1);
        min_self(ans[i], temp);
        min_self(ans[i], ansi);
        if(ans[i]>=n) {
            ans[i] = -1;
        }
    }
    rep(i,0,n) {
        // assert(ans[i] <n);
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}