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
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vi v;
    v.push_back(-1);
    rep(i,0,n) {
        if(s[i]=='1') {
            v.push_back(i);
        }
    }
    v.push_back(n);
    vi ans(n,0);
    rep(i,1,sz(v)) {
        if(v[i]-v[i-1]==2) {
            cout <<"NO\n";
            return;
        }
        if(v[i]<n) {
            ans[v[i]] = v[i]+1;
        }
    }
    rep(i,1,sz(v)) {
        int knn = v[i]+1;
        rep(j,1,v[i]-v[i-1]) {
            ans[v[i-1]+j] = knn-j;
        }
    }
    cout <<"YES\n";
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