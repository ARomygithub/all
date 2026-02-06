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

const int mxn=15e3;
int n;
vector<pii> ans;

void doSolve(int l, int r, int b2) {
    for(int step=1;step<b2;step*=2) {
        for(int i=l;i<=r;i+=step*2) {
            rep(j,0,step) {
                ans.push_back({i+j, i+j+step});
            }
        }
    }
}

void solve() {
    cin >>n;
    int b2 = 1;
    while(b2*2<n) {
        b2 *=2;
    }
    if(n>2) {
        doSolve(1,b2,b2);
        doSolve(n-b2+1,n,b2);
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