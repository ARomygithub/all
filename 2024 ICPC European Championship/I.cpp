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

const int mxn=1e3;
ll n, r[mxn], c[mxn];
pll xy[mxn];
int rd[2];
bool ok=1;

ll dist(int i, int j) {
    return 1ll*(xy[i].fi-xy[j].fi)*(xy[i].fi-xy[j].fi) + 1ll*(xy[i].se-xy[j].se)*(xy[i].se-xy[j].se);
}

void dfs(int u) {
    rep(i,0,n) {
        if(i==u) continue;
        if(dist(i,u)!=1ll*(r[i]+r[u])*(r[i]+r[u])) continue;
        if(c[i]==-1) {
            c[i] = 1-c[u];
            rd[c[i]]++;
            dfs(i);
        } else {
            if(c[i]==c[u]) {
                ok = 0;
            }
        }
    }
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>xy[i].fi >>xy[i].se >>r[i];
    }
    rep(i,0,n) {
        c[i] = -1;
    }
    rep(i,0,n) {
        if(c[i]==-1) {
            rd[0] = 0;
            rd[1] = 0;
            c[i] = 0;
            rd[0]++;
            ok = 1;
            dfs(i);
            if(ok) {
                if(max(rd[0],rd[1])>min(rd[0],rd[1])) {
                    cout <<"YES\n";
                    return;
                }
            }
        }
    }
    cout <<"NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}