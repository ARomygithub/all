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
typedef pair<pii,int> piii;
typedef pair<int,ll> pil;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m,k;

void solve() {
    cin >>n >>m >>k;
    vector<piii> v(k);
    rep(i,0,k) {
        cin >>v[i].fi.fi >>v[i].fi.se >>v[i].se;
    }
    int curn = n, curm = m;
    set<int> udhn, udhm;
    map<int,ll> mp;
    per(i,k-1,-1) {
        auto [ba,x] = v[i];
        auto [b,a] = ba;
        if(b==1) {
            if(udhn.find(a)==udhn.end()) {
                udhn.insert(a);
                mp[x] += curm;
                curn--;
            }
        } else {
            if(udhm.find(a)==udhm.end()) {
                udhm.insert(a);
                mp[x] += curn;
                curm--;
            }
        }
    }
    mp[0] += 1ll*curn*curm;
    vector<pil> ans;
    for(auto [x,ct]: mp) {
        if(ct>0) {
            ans.push_back({x,ct});
        }
    }
    sort(ans.begin(),ans.end());
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}