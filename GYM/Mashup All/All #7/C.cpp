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

const int mxn=3e5;
int n;
int x[mxn],y[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    multiset<int> mx,my;
    rep(i,0,n) {
        mx.insert(x[i]);
        my.insert(y[i]);
    }
    int ans4 = (*(--mx.end())) - (*mx.begin()) + (*(--my.end())) - (*my.begin());
    ans4 *= 2;
    vi ans(n-2,ans4);
    ans[0] = 0;
    rep(i,0,n) {
        mx.erase(mx.find(x[i]));
        my.erase(my.find(y[i]));
        max_self(ans[0], (*(--mx.end()))-x[i] + (*(--my.end()))-y[i]);
        max_self(ans[0], x[i]-(*mx.begin()) + y[i]-(*my.begin()));
        max_self(ans[0], (*(--mx.end()))-x[i] + y[i]-(*my.begin()));
        max_self(ans[0], x[i]-(*mx.begin()) + (*(--my.end()))-y[i]);
        mx.insert(x[i]);
        my.insert(y[i]);
    }
    ans[0] *=2;
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}