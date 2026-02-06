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
int n,t;
int x[mxn],y[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i];
    }
    rep(i,0,n) {
        cin >>y[i];
    }
    if((n%2)==0) {
        cout <<"Ya\n";
        return;
    }
    int dif = 0;
    for(int i=0;i<n;i+=2) {
        if(i==n-1) {
            if(dif==y[i]-x[i]) {
                cout <<"Ya\n";
            } else {
                cout <<"Tidak\n";
            }
            return;
        }
        dif = y[i]-x[i]-dif;
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