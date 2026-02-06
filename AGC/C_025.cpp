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
int n;
pii lr[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>lr[i].fi >>lr[i].se;
    }
    ll ans = 0;
    vector<int> vl,vr;
    rep(i,0,n) {
        vl.push_back(lr[i].fi);
        vr.push_back(lr[i].se);
    }
    sort(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());
    ll dif = 0;
    rep(i,0,sz(vr)) {
        int il = n-1-i;
        max_self(ans, dif+vl[il]+abs(vl[il]));
        max_self(ans, dif-vr[i]+abs(vr[i]));
        max_self(ans, dif+vl[il]*2-vr[i]+abs(vr[i]));
        max_self(ans, dif+vl[il]+abs(vl[il])-vr[i]*2);
        if(vl[il]>vr[i]) {
            dif += (vl[il]-vr[i])*2;
        } else {
            break;
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