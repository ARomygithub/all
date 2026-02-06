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

const int mxn=3e5;
int n,m;
using piii = pair<pii,int>;

void solve() {
    cin >>n >>m;
    vi ans(n,0);
    vector<piii> v;
    rep(i,0,m) {
        int l,r,x; cin >>l >>r >>x; l--,r--,x--;
        if(x>l) {
            v.push_back({{l,(i+1)},x});
            v.push_back({{x,-(i+1)},x});
        }
        if(x<r) {
            v.push_back({{x+1,(i+1)},x});
            v.push_back({{r+1,-(i+1)},x});
        }
    }
    sort(all(v));
    int id = 0;
    set<pii> s;
    rep(i,0,n) {
        while(id<sz(v) && v[id].fi.fi==i) {
            auto [lp,x] = v[id];
            auto [l,p] = lp;
            if(p>0) {
                s.insert({p,x});
            } else {
                s.erase({abs(p),x});
            }
            id++;
        }
        if(sz(s)) {
            auto val = (*(s.begin())).se;
            ans[i] = val+1;
        }
    }
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