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

const int mxn=2e5;
int n;
ll l[mxn],r[mxn];

bool valid(int i, ll val) {
    return l[i]<=val && val<=r[i];
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>l[i] >>r[i];
    }
    pll rg = {0ll,0ll};
    rep(i,0,n) {
        rg.fi += l[i];
        rg.se += r[i];
        // cout <<rg.fi <<" " <<rg.se <<endl;
    }
    if(rg.se<0ll || rg.fi>0ll) {
        cout <<"No\n";
        return;
    }
    vector<ll> ans(n,0);
    ll pos = 0;
    per(i,n-1,-1) {
        pll rgb = {rg.fi-l[i],rg.se-r[i]};
        if(valid(i, pos-rgb.fi)) {
            ans[i] = pos-rgb.fi;
            pos = rgb.fi;
        } else if(valid(i, pos-rgb.se)) {
            ans[i] = pos-rgb.se;
            pos = rgb.se;
        } else if(rgb.fi<=pos-l[i] && pos-l[i]<=rgb.se) {
            ans[i] = l[i];
            pos -= l[i];
        } else if(rgb.fi<=pos-r[i] && pos-r[i]<=rgb.se) {
            ans[i] = r[i];
            pos -= r[i];
        }
        rg = rgb;
    }
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