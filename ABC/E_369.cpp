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

using piii = pair<pii,int>;
const int mxn=400,mxm=2e5;
int n,m,q;
piii ed[mxm];

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
    int n = sz(m);
    rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
    rep(k,0,n) rep(i,0,n) rep(j,0,n)
        if (m[i][k] != inf && m[k][j] != inf) {
            auto newDist = max(m[i][k] + m[k][j], -inf);
            m[i][j] = min(m[i][j], newDist);
        }
    rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
        if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

void solve() {
    cin >>n >>m;
    vector mt(n, vector<ll>(n,inf));
    rep(i,0,n) {
        mt[i][i] = 0;
    }
    rep(i,0,m) {
        int u,v,t; cin >>u >>v >>t; u--,v--;
        ed[i] = {{u,v},t};
        min_self(mt[u][v], 1ll*t);
        min_self(mt[v][u], 1ll*t);
    }
    floydWarshall(mt);
    cin >>q;
    while(q--) {
        int ki; cin >>ki;
        vi idx;
        rep(i,0,ki) {
            int bi; cin >>bi; bi--;
            idx.push_back(bi);
        }
        ll ans = 1e18;
        do {
            rep(bit,0,(1<<ki)) {
                ll temp = 0;
                int u = 0;
                rep(j,0,ki) {
                    auto [uva, t] = ed[idx[j]];
                    auto [ua,va] = uva;
                    if((bit>>j)&1) {
                        swap(ua,va);
                    } 
                    temp += mt[u][ua] + t;
                    u = va;
                }
                temp += mt[u][n-1];
                min_self(ans, temp);
            }
        } while(next_permutation(all(idx)));
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}