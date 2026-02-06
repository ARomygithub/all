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
const ll mod = 1e9+7;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    bool ok = 1;
    int temp = n-1;
    ll ans = 1;
    for(int i = n-1;i>=0;i-=2) {
        ok &= a[i]==temp;
        if(i>0) {
            ok &= a[i-1]==temp;
            ans = ans*2%mod;
        }
        temp -=2;
    }
    if(ok) {
        cout <<ans <<"\n";
    } else {
        cout <<"0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}