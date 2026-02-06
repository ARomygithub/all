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
int n,m,k,d;
vector<pii> adj[mxn];
int x[mxn+1];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cin >>k;
    vector<int> ans(n,-1);
    priority_queue<pii,vector<pii>,greater<pii>> pq,pq2;
    set<int> sk;
    rep(i,0,k) {
        int ki; cin >>ki; ki--;
        ans[ki] = 0;
        sk.insert(ki);
    }
    for(int ki: sk) {
        for(auto [w,v]: adj[ki]) {
            if(ans[v]!=-1) continue;
            pq.push({w,v});
        } 
    }
    cin >>d;
    rep(i,1,d+1) {
        cin >>x[i];
    }

    rep(day,1,d+1) {
        while(sz(pq)) {
            auto p = pq.top();
            if(p.fi>x[day]) break;
            pq.pop();
            if(ans[p.se]!=-1) continue;
            pq2.push(p);
        }
        while(sz(pq2)) {
            auto p = pq2.top(); pq2.pop();
            if(ans[p.se]!=-1) continue;
            ans[p.se] = day;
            for(auto [w,v]: adj[p.se]) {
                if(ans[v]!=-1) continue;
                if(p.fi+w<=x[day]) {
                    pq2.push({p.fi+w,v});
                } else {
                    pq.push({w,v});
                }
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}