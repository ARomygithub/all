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

const int mxn=1e4,mxs=30;
int n;
pii xy[mxn];

void solve() {
    cin >>n;
    vector d(n, vector<double>(mxs,1e9));
    rep(i,0,n) {
        cin >>xy[i].fi >>xy[i].se;
    }
    d[0][0] = 0;
    rep(i,1,n) {
        int ct = min(mxs-1,i-1);
        rep(j,0,ct+1) {
            rep(k,0,j+1) {
                if(i-k-1 <0) break;
                min_self(d[i][j], d[i-k-1][j-k]+ hypot(1.0*abs(xy[i].fi-xy[i-k-1].fi), 1.0*abs(xy[i].se-xy[i-k-1].se)));
            }
        }
    }
    double ans = 1e9;
    rep(i,0,mxs) {
        min_self(ans, d[n-1][i]+(i>0?(1<<(i-1)):0));
    }
    cout <<fixed <<setprecision(8) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}