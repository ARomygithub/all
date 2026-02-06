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

const int mxn=1e5;
int n,m;

void solve() {
    cin >>n >>m;
    set<int> s;
    rep(i,0,m) {
        int ai,bi; cin >>ai >>bi; ai--,bi--;
        int tmp = ai-bi;
        if(tmp<0) {
            tmp += n;
        }
        s.insert(tmp);
    }
    int id = 0;
    while(sz(s)<m) {
        s.insert(id);
        id++;
    }
    vector<pii> ans;
    for(int si : s) {
        rep(i,si,n) {
            ans.push_back({i+1, i-si+1});
        }
        rep(i,0,si) {
            ans.push_back({i+1, i-si+n+1});
        }
    }
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