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
#define dbg(x) cerr <<#x <<": " <<x <<endl;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5,mxr=20;
int n,t;
using piii = pair<pii,int>;

void solve() {
    cin >>n;
    vector circ(mxr+1, vector<bool>(360,0));
    vector rad(mxr+1, vector<bool>(360,0));
    rep(i,0,n) {
        char wt; cin >>wt;
        if(wt=='C') {
            int r,t1,t2; cin >>r >>t1 >>t2;
            for(int j=t1;j!=t2;j=(j+1)%360) {
                circ[r][j] = 1;
            }
        } else {
            int r1,r2,ti; cin >>r1 >>r2 >>ti;
            rep(j,r1,r2) {
                rad[j][ti] = 1;
            }
        }
    }
    vector vis(mxr, vector<bool>(360,0));
    queue<pii> q;
    auto push = [&](int r, int th) -> void {
        if(!vis[r][th]) {
            q.push({r,th});
            vis[r][th] = 1;
        }
    };
    rep(i,0,360) {
        push(0,i);
    }
    while(sz(q)) {
        auto [r,a] = q.front(); q.pop();
        if(r+1<mxr && !circ[r+1][a]) {
            push(r+1,a);
        }
        if(r>0 && !circ[r][a]) {
            push(r-1,a);
        }
        int nx = (a+1)%360;
        int pr = (a-1+360)%360;
        if(!rad[r][nx]) {
            push(r,nx);
        }
        if(!rad[r][a]) {
            push(r,pr);
        }
    }
    rep(i,0,360) {
        if(vis[mxr-1][i] && (!circ[mxr][i])) {
            cout <<"YES\n";
            return;
        }
    }
    cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}