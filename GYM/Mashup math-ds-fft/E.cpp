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

const int mxn=700;
int n;
int a[mxn];

using tp = tuple<int,int,int>;
void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi l(n),r(n);
    iota(all(l),0);
    iota(all(r),0);
    priority_queue<tp> pq;
    rep(i,0,n) {
        pq.push({0,0,i});
        pq.push({0,1,i});
    }
    vector<vi> adj(n);
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            if(__gcd(a[i],a[j])>1) {
                adj[i].push_back(j);
            }
        }
    }
    while(sz(pq)) {
        auto [len,ty,u] = pq.top(); pq.pop();
        int cur = ty==0?l[u]:r[u];
        if(abs(u-cur)>len) continue;
        auto it = lower_bound(all(adj[u]),l[u]-1);
        while(it!=adj[u].end() && (*it)<=r[u]+1) {
            int pr = (*it);
            if(pr<u) {
                if(r[pr]<r[u]) {
                    r[pr] = r[u];
                    pq.push({r[pr]-pr,1,pr});
                }
            } else {
                
            }
            it++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}