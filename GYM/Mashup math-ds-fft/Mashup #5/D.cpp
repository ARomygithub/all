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

const int mxn=4e5,mxc=640;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    vector<pii> v;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && a[j]==a[i]) {
            j++;
        }
        v.push_back({j-i,a[i]});
        i = j;
    }
    sort(all(v));
    vi pr(sz(v)+1,0);
    rep(i,1,sz(pr)) {
        pr[i] = pr[i-1] + v[i-1].fi;
    }
    int ans = 0, ic = -1;
    int inf = 1e9;
    rep(ct,1,mxc+1) {
        if(ct*ct>n) break;
        int sm = 0;
        auto it = lower_bound(all(v),pii{ct,-inf})-v.begin();
        sm = (sz(v)-it)*ct + pr[it];
        if(sm>=ct*ct) {
            sm -= (sm%ct);
            if(sm>ans) {
                ans = sm;
                ic = ct;
            }
        }
    }
    cout <<ans <<"\n";
    int p = ic, q = ans/ic;
    vi tmp;
    per(j,sz(v)-1,-1) {
        auto [ct, val] = v[j];
        if(sz(tmp)==ans) break;
        rep(i,0,min(ct,ic)) {
            tmp.push_back(val);
            if(sz(tmp)==ans) break;
        }
    }
    vector vans(p, vi(q));
    for(int i=0;i<sz(tmp);i+=ic) {
        int i0 = i/ic;
        rep(j,0,ic) {
            vans[j][(i0+j)%q] = tmp[i+j];
        }
    }
    cout <<p <<" " <<q <<"\n";
    rep(i,0,sz(vans)) {
        rep(j,0,sz(vans[i])) {
            cout <<vans[i][j] <<" \n"[j==sz(vans[i])-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}