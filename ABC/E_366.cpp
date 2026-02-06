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
int n,d;

void solve() {
    cin >>n >>d;
    vector<int> x(n),y(n);
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<ll> prefx(n+1,0),prefy(n+1,0);
    rep(i,0,n) {
        prefx[i+1] = prefx[i]+x[i];
    }
    rep(i,0,n) {
        prefy[i+1] = prefy[i]+y[i];
    }
    int le = x[n-1]-d, ri = x[0]+d;
    ll ans = 0;
    int ym = y[(n-1)/2];
    auto getYd = [&](int yi) -> ll {
        int it = lower_bound(y.begin(),y.end(),yi)-y.begin();
        ll yd = prefy[n]-1ll*(n-it*2)*yi-prefy[it]*2;
        return yd;
    };
    rep(xi,le,ri+1) {
        int it = lower_bound(x.begin(),x.end(),xi)- x.begin();
        ll xd = prefx[n]-1ll*(n-it*2)*xi-prefx[it]*2;
        if(getYd(ym)+xd<=d) {
            int li=-1,ri=-1;
            int l = -2e6, r=ym;
            while(l<=r) {
                int mid = (l+r)/2;
                ll yd = getYd(mid);
                if(yd+xd<=d) {
                    li = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            l=ym,r=2e6;
            while(l<=r) {
                int mid = (l+r)/2;
                ll yd = getYd(mid);
                if(yd+xd<=d) {
                    ri = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            ans += (ri-li+1);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}