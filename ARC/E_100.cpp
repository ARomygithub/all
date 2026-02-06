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

const int mxn=18;
int n;
int a[1<<mxn];

void solve() {
    cin >>n;
    rep(i,0,1<<n) {
        cin >>a[i];
    }
    vector<pii> g(1<<n, {-1,-1});
    rep(S,1,1<<n) {
        if(a[0]>=a[S]) {
            g[S] = {0,S};
        } else {
            g[S] = {S,0};
        }
    }
    rep(i,0,n) {
        rep(S,0,1<<n) {
            if((S>>i)&1) {
                int pr = S^(1<<i);
                vector<int> temp({g[pr].fi, g[pr].se});
                for(auto idx: temp) {
                    if(idx==-1) continue;
                    if(idx==g[S].fi || idx==g[S].se) continue;
                    if(a[idx]>a[g[S].fi]) {
                        g[S].se = g[S].fi;
                        g[S].fi = idx;
                    } else if(a[idx]>a[g[S].se]) {
                        g[S].se = idx;
                    }
                }
            }
        }
    }
    int ls = 0;
    vector<int> ans(1<<n);
    rep(i,1,1<<n) {
        ans[i] = a[g[i].fi]+a[g[i].se];
        max_self(ans[i],ls);
        max_self(ls,ans[i]);
    }
    rep(i,1,1<<n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}