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
int n;
ll b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>b[i];
    }
    vector v(60, queue<ll>());
    rep(i,0,n) {
        ll pw = 0;
        while((1ll<<pw)*2<=b[i]) {
            pw++;
        }
        v[pw].push(b[i]);
    }
    vector<ll> ans;
    ll xr = 0;
    rep(i,0,n) {
        bool ok = 0;
        rep(j,0,60) {
            if(!((xr>>j)&1) && sz(v[j])) {
                ok = 1;
                ll cur = v[j].front(); v[j].pop();
                ans.push_back(cur);
                xr ^= cur;
                break;
            }
        }
        if(!ok) {
            cout <<"No\n";
            return;
        }
    }
    // ll xr = 0;
    // rep(i,0,sz(ans)) {
    //     ll xrn = xr^ans[i];
    //     if(xr>=xrn) {
    //         cout <<"No\n";
    //         return;
    //     }
    //     xr = xrn;
    // }
    cout <<"Yes\n";
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}