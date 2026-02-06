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
int n;
ll k;
int x[mxn],a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>x[i]; x[i]--;
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    vector jmp(60, vi(n));
    rep(i,0,n) {
        jmp[0][i] = x[i];
    }
    rep(bt,1,60) {
        rep(i,0,n) {
            jmp[bt][i] = jmp[bt-1][jmp[bt-1][i]];
        }
    }
    vi ans(n);
    rep(i,0,n) {
        int u = i;
        for(ll j=0;j<60;j++) {
            if((k>>j)&1) {
                u = jmp[j][u];
            }
        }
        ans[i] = a[u];
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