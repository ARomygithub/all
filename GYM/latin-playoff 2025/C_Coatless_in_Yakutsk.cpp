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

const int mxn=1e5;
int n,c,t;
int a[mxn];

void solve() {
    cin >>c >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = -50;
    int l = -49, r = 50;
    while(l<=r) {
        int mid = (l+r)/2;
        int ct = 0;
        bool ok = 1;
        rep(i,0,n) {
            if(a[i]<mid) {
                ct++;
                if(ct>c) {
                    ok = 0;
                    break;
                }
            } else {
                ct = 0;
            }
        }
        if(ok) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
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