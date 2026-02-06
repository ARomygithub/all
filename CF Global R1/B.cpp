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
int n,m,k;
int b[mxn];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<int> v;
    rep(i,0,n-1) {
        v.push_back(b[i+1]-b[i]-1);
    }
    sort(v.begin(),v.end());
    int ans = n;
    if(n>k) {
        rep(i,0,n-k) {
            ans += v[i];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}