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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n,t;
int a[mxn][mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>a[i][j];
        }
    }
    vector<int> ans(n);
    rep(i,0,n) {
        ans[i] = (1<<30)-1;
        rep(j,0,n) {
            if(j==i) continue;
            ans[i] &=a[i][j];
            ans[i] &=a[j][i];
        }
    }
    bool flag=1;
    rep(i,0,n) {
        rep(j,0,n) {
            if(i!=j) {
                if(a[i][j]!=(ans[i]|ans[j])) {
                    flag = 0;
                }
            }
        }
    }
    if(flag) {
        cout <<"YES\n";
        rep(i,0,n) {
            cout <<ans[i] <<" \n"[i==n-1];
        }
    } else {
        cout <<"NO\n";
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