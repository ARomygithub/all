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

const int mxn=1e4+2;
int n;
ll th;

void solve() {
    cin >>n >>th;
    vi w(n+2,0);
    vector<pii> c(n+2);
    rep(i,2,n+2) {
        int x; cin >>x;
        assert(x==i);
        cin >>c[i].fi >>c[i].se >>w[i];
    }
    vi cw(n+2,0);
    vector<bitset<mxn>> vs(n+2);
    per(i,n+1,-1) {
        vs[i].set(i);
        if(i>1) {
            int ci = c[i].fi;
            {
                vs[ci]  = vs[ci] | vs[i];
            }
            ci = c[i].se;
            {
                vs[ci] = vs[ci] | vs[i];
            }
        }
    }
    rep(i,0,n+2) {
        rep(j,i,n+2) {
            if(vs[i][j]) {
                cw[i] += w[j];
            }
        }
    }
    vector<pii> ans;
    rep(i,2,n+1) {
        if(cw[i]>=th) {
            ans.push_back({i,cw[i]});
        }
    }
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
    cout <<sz(ans) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}