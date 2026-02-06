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
pii uv[mxn];

void solve() {
    cin >>n >>m; m--;
    rep(i,0,n) {
        cin >>uv[i].fi >>uv[i].se; uv[i].se--;
    }
    sort(uv,uv+n);
    int l = 1;
    int ans = 0;
    for(int i=0;i<n;) {
        auto [u,v] = uv[i];
        if(l<=m) {
            int temp = min(u,m+1)-l;
            ans += max(temp,0);
        }
        while(i+1<n && uv[i+1].fi<=v) {
            max_self(v, uv[i+1].se);
            i++;
        }
        l = v+1;
        i++;
    }
    if(l<=m) {
        ans += m-l+1;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}