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

const int mxn=5e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi ri(n,-1);
    int knn = -1;
    vector v(n+1, vi());
    rep(i,0,n) {
        v[a[i]].push_back(i);
    }
    rep(i,1,n+1) {
        for(auto j: v[i]) {
            ri[j] = max(knn,j);
        }
        for(auto j: v[i]) {
            max_self(knn, j);
        }
    }
    vi ans(n,0);
    for(int i=0;i<n;) {
        int j = i;
        int mx = 0;
        int ri1 = ri[i];
        while(j<n && j<=ri1) {
            max_self(mx, a[j]);
            max_self(ri1, ri[j]);
            j++;
        }
        rep(k,i,j) {
            ans[k] = mx;
        }
        i = j;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}