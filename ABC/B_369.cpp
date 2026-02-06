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

const int mxn=1e2;
int n;
int a[mxn];
char c[mxn];

void solve() {
    cin >>n;
    vi vl,vr;
    rep(i,0,n) {
        cin >>a[i] >>c[i];
        if(c[i]=='L') {
            vl.push_back(a[i]);
        } else {
            vr.push_back(a[i]);
        }
    }
    int ans = 0;
    rep(i,1,sz(vl)) {
        ans += abs(vl[i]-vl[i-1]);
    }
    rep(i,1,sz(vr)) {
        ans += abs(vr[i]-vr[i-1]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}