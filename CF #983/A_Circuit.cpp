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

const int mxn=50;
int n,t;
int a[mxn*2];

void solve() {
    cin >>n;
    rep(i,0,n*2) {
        cin >>a[i];
    } 
    vi ct(2);
    rep(i,0,n*2) {
        ct[a[i]]++;
    }
    int mn = n - (ct[0]/2) - (ct[1]/2);
    int mx = min(ct[0],ct[1]);
    cout <<mn <<" " <<mx <<"\n";
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