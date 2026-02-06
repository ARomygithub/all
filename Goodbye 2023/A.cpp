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

const int mxn=5;
int n,k,t;
int b[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>b[i];
    }
    int sisa = 2023;
    rep(i,0,n) {
        if((sisa%b[i])!=0) {
            cout <<"NO\n";
            return;
        }
        sisa /=b[i];
    }
    cout <<"YES\n";
    rep(i,0,k) {
        if(i==k-1) {
            cout <<sisa <<"\n";
        } else {
            cout <<"1 ";
        }
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