#include<bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define rep(i, a, b) for(int i = a; i < (b);i++)
#define per(i, a, b) for(int i= a; i > (b);i--) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define se second
#define fi first

int n,m;
using psi = pair<string,int>;

void solve() {
    cin >>n >>m;
    vector<string> s(n);
    rep(i,0,n) {
        cin >>s[i];
    }    
    vector<psi> vs;
    rep(i,0,n) {
        vs.push_back({s[i],i});
    }
    sort(all(vs));
    vi vord(n,-1);
    vi ans(m,-1);
    rep(i,0,n) {
        vord[i] = vs[i].se;
    }
    ans[0] = vord.back();
    per(i,m-1,0) {
        int id = i;
        vector vx(2, vi());
        rep(j,0,n) {
            vx[s[vord[j]][id]-'0'].push_back(vord[j]);
        }
        vi vord_new;
        rep(j,0,2) {
            for(auto& x: vx[j]) {
                vord_new.push_back(x);
                // what_is(x);
            }
        }
        vord.swap(vord_new);
        ans[i] = vord.back();
    }
    rep(i,0,m) {
        cout <<ans[i]+1 <<" \n"[i==m-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}