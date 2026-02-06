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

const int mxn=8;
int n,mg,mh;
bool g[mxn][mxn], h[mxn][mxn];
int a[mxn][mxn];

void solve() {
    cin >>n;
    cin >>mg;
    rep(i,0,mg) {
        int u,v; cin >>u >>v; u--,v--;
        g[u][v] = 1;
    }
    cin >>mh;
    rep(i,0,mh) {
        int u,v; cin >>u >>v; u--,v--;
        h[u][v] = 1;
    }
    rep(i,0,n) {
        rep(j,i+1,n) {
            cin >>a[i][j];
        }
    }
    vi idx(n);
    iota(all(idx),0);
    int ans = 2e9;
    do {
        int temp = 0;
        rep(i,0,n) {
            rep(j,i+1,n) {
                auto [mn,mx] = minmax(idx[i],idx[j]);
                if(g[i][j] != h[mn][mx]) {
                    temp += a[mn][mx];
                }
            }
        }
        min_self(ans,temp);
    } while(next_permutation(all(idx)));
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}