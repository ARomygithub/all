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

const int mxn=15;
int n,d;
int w[mxn];
ll ans=LLONG_MAX;

void dfs(int pos, vector<ll>& x) {
    if(pos == n) {
        ll temp = 0;
        for(ll xi : x) {
            temp +=xi*xi;
        }
        min_self(ans, temp);
        return;
    }
    rep(i,0,d) {
        x[i] +=w[pos];
        if(x[i]*x[i]<LLONG_MAX) {
            dfs(pos+1, x);
        } 
        x[i] -=w[pos];
    }
}

void solve() {
    cin >>n >>d;
    ll s = 0;
    rep(i,0,n) {
        cin >>w[i];
        s +=w[i];
    }
    sort(w,w+n);
    vector<ll> x(d,0);
    // rep(i,n-d+3,n) {
    //     x[i-(n-d)] = w[i];
    // }
    dfs(0, x);
    double ans2 = 1.0*s*s/d;
    ans2 = 1.0*ans-ans2;
    ans2 /= 1.0*d;
    cout <<fixed <<setprecision(8) <<ans2 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}