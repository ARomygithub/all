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

const int mxn=1e5;
int t;
ll n;

void solve() {
    cin >>n;
    vi v = {2,3,5,7};
    ll sm = 0;
    rep(bit,1,(1<<4)) {
        int ct = 0;
        int mul = 1;
        rep(j,0,4) {
            if((bit>>j)&1) {
                ct++;
                mul *= v[j];
            }
        }
        if(ct%2) {
            sm += (n/mul);
        } else {
            sm -= (n/mul);
        }
    }
    cout <<n-sm <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}