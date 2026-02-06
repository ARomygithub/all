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

const int mxn=3e5;
int n,m;
int l[mxn+1],r[mxn+1],vis[mxn+1],d0[mxn+1],ans[mxn+1];
vector<int> t[mxn+1];
void ns() {puts("-1");exit(0);}
void topu1() {
    static int st[mxn+1],d[mxn+1]; int top=0;
    rep(i,1,n+1) {
        d[i] = d0[i];
        if(!d[i]) st[++top]=i;
    }
    while(top) {
        int u = st[top--];
        for(int v: t[u]) {
            if(!--d[v]) {
                st[++top] = v;
            }
        }
    }
    rep(i,1,n+1) {
        if(d[i]) ns();
    }
}
int dfs(int u) {
    if(vis[u]) return r[u];vis[u] = 1;
    for(int v: t[u]) {
        min_self(r[u], dfs(v)-1);
    }
    return r[u];
}
struct nd {
    int x,id;
    bool operator<(const nd b)const{return x>b.x;}
};
void topu() {
    static int d[mxn+1];
    priority_queue<nd> q1,q2;
    rep(i,1,n+1) {
        d[i] = d0[i];
        if(!d[i]) q1.push({l[i],i});
    }
    rep(i,1,n+1) {
        while(!q1.empty() && q1.top().x<=i) {
            int j=q1.top().id; q1.pop();
            q2.push({r[j],j});
        }
        if(q2.empty()) ns();
        int u = q2.top().id; q2.pop();
        if(r[u]<i) ns();
        ans[i] = u;
        for(int v: t[u]) {
            if(!--d[v]) q1.push({l[v],v});
        }
    }
}

void solve() {
    cin >>n >>m;
    rep(i,1,n+1) {
        cin >>l[i] >>r[i];
    }
    rep(i,1,m+1) {
        int u,v; cin >>u >>v;++d0[v];
        t[u].push_back(v);
    }
    topu1();
    rep(i,1,n+1) {
        dfs(i);
    }
    topu();
    rep(i,1,n+1) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}