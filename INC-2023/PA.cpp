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

const int mxn=200;
int n,m;
int a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    int ct=0,mx=0;
    rep(i,0,n) {
        rep(j,i+1,n) {
            rep(k,j+1,n) {
                if(a[k]-a[i]<=m) {
                    ct++;
                    max_self(mx, a[i]+a[j]+a[k]);
                }
            }
        }
    }
    if(ct==0) {
        cout <<"-1\n";
    } else {
        cout <<ct <<" " <<mx <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}