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
int n,t;
int l[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>l[i];
    }
    vi fl(n+1,1);
    rep(i,0,n+1) {
        fl[i] = 0;
        if(i<n && l[i]) {
            break;
        }
    }
    per(i,n,-1) {
        fl[i] = 0;
        if(i>0 && l[i-1]) {
            break;
        }
    }
    int ans = 0;
    rep(i,0,n+1) {
        ans += fl[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}