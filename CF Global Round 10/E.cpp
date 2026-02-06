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

const int mxn=25;
int n;
ll a[mxn][mxn];

void solve() {
    cin >>n;
    a[0][0] = 0;
    rep(ij,1,n*2-1) {
        rep(i,max(0,ij-n+1),min(n,ij+1)) {
            a[i][ij-i] = (1ll<<ij)*(i%2);
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            cout <<a[i][j] <<" \n"[j==n-1];
        }
    }
    cout <<flush;
    int q; cin >>q;
    while(q--) {
        ll s; cin >>s;
        vector<pii> ans;
        pii u = {n-1,n-1};
        while(u != make_pair(0,0)) {
            ans.push_back(u);
            s -= a[u.fi][u.se];
            if((u.fi%2) == ((s>>(u.fi+u.se-1))&1)) {
                u.se--;
            } else {
                u.fi--;
            }
        }
        ans.push_back(u);
        reverse(ans.begin(),ans.end());
        rep(i,0,sz(ans)) {
            cout <<ans[i].fi+1 <<" " <<ans[i].se+1 <<"\n";
        }
        cout <<flush;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}