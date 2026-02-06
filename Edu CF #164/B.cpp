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

const int mxn=3e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    bool same = 1;
    rep(i,1,n) {
        same = same && (a[i]==a[i-1]);
    }
    if(same) {
        cout <<"-1\n";
        return;
    }
    int ans = n;
    vector<int> v;
    rep(i,0,n) {
        if(a[i]!=a[0]) {
            min_self(ans,i);
            min_self(ans, n-i-1);
            v.push_back(i);
        }
    }
    rep(i,1,sz(v)) {
        min_self(ans, v[i]-v[i-1]-1);
    }
    cout <<ans <<"\n";
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