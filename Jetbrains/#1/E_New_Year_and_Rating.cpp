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
int c[mxn],d[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>c[i] >>d[i];
    }
    bool inf = 1;
    rep(i,0,n) {
        if(d[i]==2) {
            inf = 0;
            break;
        }
    } 
    if(inf) {
        cout <<"Infinity\n";
        return;
    }
    int l = -1e8, r = 1e8;
    int lwr = -1e9;
    int ans = lwr;
    while(l<=r) {
        int mid = (l+r)/2;
        int ok = 0;
        int u = mid;
        rep(i,0,n) {
            if(d[i]==1 && u<1900) {
                ok = -1;
                break;
            }
            if(d[i]==2 && u>=1900) {
                ok = 1;
                break;
            }
            u += c[i];
        }
        if(ok==0) {
            ans = u;
            l = mid+1;
        } else if(ok<0) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    if(ans==lwr) {
        cout <<"Impossible\n";
    } else {
        cout <<ans <<"\n";
    }
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