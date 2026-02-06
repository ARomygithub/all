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

const int mxn=1e3;
int n,k,t;
int a[mxn];

void solve() {
    cin >>n >>k;
    if(k>1 && k<n) {
        cout <<"-1\n";
        return;
    }
    if(k==n) {
        rep(i,0,n) {
            a[i] = 1;
        }
    } else if(k==1) {
        rep(i,0,n) {
            a[i] = i+1;
        }
    } else if(k==0) {
        if(n>2) {
            rep(i,0,n) {
                a[i] = n-i;
            }
        } else {
            cout <<"-1\n";
            return;
        }
    }
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
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