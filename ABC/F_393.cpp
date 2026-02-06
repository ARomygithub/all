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
int n,q;
int a[mxn];
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ipii> qry;
    rep(i,0,q) {
        int r,x; cin >>r >>x; r--;
        qry.push_back({r,{x,i}});
    }
    vi ans(q,1);
    sort(all(qry));
    int now = 0;
    vi v;
    rep(i,0,q) {
        auto [r,xi] = qry[i];
        auto [x,id] = xi;
        while(now<=r) {
            auto it = lower_bound(all(v),a[now]);
            if(it==v.end()) {
                v.push_back(a[now]);
            } else {
                (*it) = a[now];
            }
            now++;
        }
        auto it = upper_bound(all(v),x);
        ans[id] = (it-v.begin());
    }
    rep(i,0,q) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}