#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,m;

void solve() {
    cin >>n >>m;
    vi ls(m,-1);
    vector<vi> vp;
    rep(i,0,n) {
        int pi; cin >>pi;
        vi vc(pi);
        rep(j,0,pi) {
            cin >>vc[j]; vc[j]--;
        }
        vp.push_back(vc);
    }
    rep(i,0,n) {
        rep(j,0,sz(vp[i])) {
            ls[vp[i][j]] = i;
        }
    }
    vector vl(n,set<int>());
    rep(i,0,m) {
        if(ls[i]!=-1) {
            vl[ls[i]].insert(i);
        }
    }
    rep(i,1,n) {
        bool ok = 1;
        for(auto bij : vp[i-1]) {
            if(vl[i].count(bij)) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            cout <<"Yes\n";
            vi ans(n);
            iota(all(ans),0);
            swap(ans[i-1],ans[i]);
            rep(j,0,n) {
                cout <<ans[j]+1 <<" \n"[j==n-1];
            }
            return;
        }
    }
    cout <<"No\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
}