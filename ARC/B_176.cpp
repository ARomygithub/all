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
const int d[4] = {6,2,4,8};
int t;
ll n,m,k;

void solve() {
    cin >>n >>m >>k;
    if(n<m) {
        if(m==n+1 && k == n) {
            cout <<"0\n";
        } else {
            // n
            cout <<d[n%4] <<"\n";
        }
    } else {
        if(m-k==1) {
            cout <<"0\n";
            return;
        }
        ll ret = (n-k)%(m-k);
        ret += k;
        // ret
        cout <<d[ret%4] <<"\n";
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