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
int b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n-1) {
        cin >>b[i];
    }
    vector<int> a(n,0);
    rep(i,0,n) {
        if(i==0) {
            a[i] = b[0];
        } else if(i==n-1) {
            a[i] = b[i-1];
        } else {
            a[i] = b[i-1]|b[i];
        }
    }
    // rep(i,0,n) {
    //     cout <<a[i] <<" \n"[i==n-1];
    // }    
    rep(i,0,n-1) {
        if((a[i]&a[i+1])!=b[i]) {
            cout <<"-1\n";
            return;
        }
    }
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
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