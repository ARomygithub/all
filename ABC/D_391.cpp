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

const int mxn=2e5;
int n,w,q;

void solve() {
    cin >>n >>w;
    vector v(w, vector<pii>());
    rep(i,0,n) {
        int x,y; cin >>x >>y; x--;
        v[x].push_back({y,i});
    }
    vi tin(n), tout(n,2e9);
    rep(i,0,w) {
        sort(all(v[i]));
    }
    rep(i,0,n) {
        bool lengkap = 1;
        int mx = 0;
        rep(j,0,w) {
            lengkap = lengkap && (sz(v[j])>i);
        }
        if(!lengkap) break;
        rep(j,0,w) {
            auto [y,id] = v[j][i];
            if(i==0) {
                tin[id] = y-1;
            } else {
                auto [yp, idp] = v[j][i-1];
                tin[id] = max(y-1, tout[idp]);
            }
            max_self(mx, tin[id]);
        }
        rep(j,0,w) {
            auto [y,id] = v[j][i];
            tout[id] = mx+1;
        }
    }
    cin >>q;
    while(q--) {
        int ti,ai; cin >>ti >>ai; ai--;
        if(tout[ai]>ti) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}