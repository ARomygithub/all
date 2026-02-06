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

const int mxn=200;
int n,t;
ll a[mxn];
string s;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    cin >>s;
    vector<ll> basis(60,0);
    auto add = [&](ll x) -> bool {
        per(i, 59, -1) {
            if((x>>i)&1) {
                if(basis[i]==0) {
                    basis[i] = x;
                    return 1;
                } else {
                    x ^= basis[i];
                    if(x==0ll) break;
                }
            }
        }
        return 0;
    };
    per(i,n-1,-1) {
        int ret = add(a[i]);
        if(ret && s[i]=='1') {
            cout <<"1\n";
            return;
        }
    }
    cout <<"0\n";
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