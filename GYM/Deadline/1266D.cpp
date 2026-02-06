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
typedef pair<ll,pii> plii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;
vector<plii> e;
// map<int,ll> mp[mxn];

void solve() {
    cin >>n >>m;
    vector<ll> ct(n,0);
    rep(i,0,m) {
        int u,v; ll d; cin >>u >>v >>d; u--,v--;
        e.push_back({d,{u,v}});
        ct[u] += d;
        ct[v] -= d;
    }
    // sort(e.begin(),e.end());
    // rep(i,0,m) {
    //     auto [d,uv] = e[i];
    //     auto [u,v] = uv;
    //     if(ct[u]>0 && ct[v]<0) {
    //         ll temp = min(d,ct[u]);
    //         min_self(temp, ct[v]*-1);
    //         mp[u][v] += temp;
    //         ct[u] -= temp;
    //         ct[v] += temp;
    //     }
    // }
    vector<plii> ans;
    queue<int> q1,q2;
    rep(i,0,n) {
        // for(auto [k,v]: mp[i]) {
        //     ans.push_back({v,{i,k}});
        // }
        if(ct[i]>0) {
            q1.push(i);
        } else if(ct[i]<0) {
            q2.push(i);
        }
    }
    while(sz(q1) && sz(q2)) {
        int u=q1.front(); int v = q2.front();
        if(ct[u]>(ct[v]*-1)) {
            ans.push_back({(ct[v]*-1), {u,v}});
            ct[u] -= (ct[v]*-1);
            ct[v] = 0;
            q2.pop();
        } else if(ct[u]<(ct[v]*-1)) {
            ans.push_back({ct[u], {u,v}});
            ct[v] += ct[u];
            ct[u] = 0;
            q1.pop();
        } else {
            ans.push_back({ct[u], {u,v}});
            ct[u] = 0;
            ct[v] = 0;
            q1.pop(); q2.pop();
        }
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].se.fi+1 <<" " <<ans[i].se.se+1 <<" " <<ans[i].fi <<"\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}