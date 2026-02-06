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
int a,b,n,t;

void solve() {
    cin >>a >>b >>n;
    if(a<b) swap(a,b);
    int ans = 0;
    while(1ll*a*2+b <=n) {
        b += a;
        a += b;
        ans +=2;
    }
    if(a>n) {
        cout <<ans <<"\n";
    } else {
        if(a+b>n) {
            cout <<ans+1 <<"\n";
        } else {
            cout <<ans+2 <<"\n";
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