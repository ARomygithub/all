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
int n,k;
int a[mxn*2];

void solve() {
    cin >>n >>k;
    rep(i,0,n*2) {
        cin >>a[i];
    }
    sort(a,a+n*2);
    for(int i=0;i<n*2;i+=2) {
        if(abs(a[i]-a[i+1])>k) {
            cout <<"Tidak\n";
            return;
        }
    }
    cout <<"Ya\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}