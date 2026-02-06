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

const int mxn=2e5;
int n;
pii a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i].fi; a[i].se = i;
    }
    vector<ll> ans(n,0);
    sort(a,a+n,greater<pii>());
    int ct=1;
    rep(i,0,n-1) {
        if(a[i+1].fi<a[i].fi) {
            ans[a[i+1].se] =ans[a[i].se]+1ll*a[i].fi*ct;
            ct = 1;
        } else {
            ans[a[i+1].se] = ans[a[i].se];
            ct++;
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