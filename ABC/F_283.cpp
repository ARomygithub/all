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

const int mxn=2e5;
int n;
int p[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>p[i];
    }
    vector<int> d(n+1, n);
    rep(i,1,n+1) {
        for(int j=1;j<=d[i]-1;j++) {
            if(i-j>0) {
                min_self(d[i], j+abs(p[i]-p[i-j]));
            }
            if(i+j<=n) {
                min_self(d[i], j+abs(p[i]-p[i+j]));
            }
        }
    }
    rep(i,1,n+1) {
        cout <<d[i] <<" \n"[i==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}