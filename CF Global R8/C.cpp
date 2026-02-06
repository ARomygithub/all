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

const int mxn=500;
int n,t;

void solve() {
    cin >>n;
    cout <<n*3+4 <<"\n";
    rep(i,0,2) {
        rep(j,0,2) {
            cout <<i <<" " <<j <<"\n";
        }
    }
    rep(i,1,n+1) {
        cout <<i+1 <<" " <<i <<"\n";
        cout <<i <<" " <<i+1 <<"\n";
        cout <<i+1 <<" " <<i+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}