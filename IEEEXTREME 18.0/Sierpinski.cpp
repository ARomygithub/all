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

const int mxn=1e5;
int x,y,t;
ll l[31];

int slv(ll xi, ll yi, int step) {
    if(step==1) {
        return 1;
    }
    if(xi<=l[step-1]) {
        return slv(xi,yi,step-1);
    }
    ll le = xi-l[step-1], ri = (l[step-1]+1)*2 - xi + le-1;
    if(yi>=le && yi<=ri) {
        return 0;
    }
    if(yi<le) {
        return slv(xi-l[step-1]-1, yi, step-1);
    } else {
        return slv(xi-l[step-1]-1, yi-ri, step-1);
    }
}

void solve() {
    cin >>x >>y;
    cout <<slv(x,y,30) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    l[1] = 2;
    rep(i,2,31) {
        l[i] = l[i-1]*2+1;
    }
    while(t--) {
        solve();
    }
}