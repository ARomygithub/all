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

const int mxn=1e5;
int n,t;
int a[mxn+1];

pii mv(int i, int x) {
    cout <<i <<" " <<x <<"\n";
    cout <<flush;
    pii ret; 
    cin >>ret.fi >>ret.se;
    return ret;
}

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector vb(30, set<int>());
    rep(i,1,n+1) {
        rep(j,0,30) {
            if((a[i]>>j)&1) {
                vb[j].insert(i);
            }
        }
    }
    int xr = 0;
    rep(i,1,n+1) {
        xr ^= a[i];
    }
    auto upd = [&](int i, int x) -> void {
        rep(j,0,30) {
            if((a[i]>>j)&1) {
                vb[j].erase(i);
            }
        }
        xr ^= a[i];
        a[i] -=x;
        xr ^= a[i];
        rep(j,0,30) {
            if((a[i]>>j)&1) {
                vb[j].insert(i);
            }
        }
    };
    if(xr==0) {
        auto [i,x] = mv(0,0);
        upd(i,x);
    }
    pii res = {-1,-1};
    while(res.fi!=0) {
        int bt = -1;
        per(j,29,-1) {
            if((xr>>j)&1) {
                bt = j;
                break;
            }
        }
        assert(bt!=-1);
        auto cur = *vb[bt].begin();
        int nx = a[cur]^xr;
        res = mv(cur, a[cur]-nx);
        upd(cur, a[cur]-nx);
        if(res.fi!=0) {
            upd(res.fi, res.se);
        }
    }
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