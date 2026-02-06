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

const int mxn=1e6;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vi cs(n+1);
    iota(all(cs),0);
    rep(i,1,n+1) {
        for(ll j=i;j<=n;j+=i) {
            if(s[j-1]=='0') {
                min_self(cs[j], i);
            } else {
                break;
            }
        }
    }
    ll ans = 0;
    rep(i,1,n+1) {
        if(s[i-1]=='0') {
            ans += cs[i];
        }
    }
    cout <<ans <<"\n";
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