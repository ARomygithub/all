#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
const ll mod = 1e9+7;
ll n,a,b,t; //b*n<=1e15

void solve() {
    cin >>n >>a >>b;
    if(n==a) {
        cout <<b*n %mod <<"\n";
    } else {
        // (1,0) - (a+1,a)
        ll temp[2] = {0ll,b/2};
        for(int i=2;i<=a;i++) {
            temp[0] = temp[1];
            temp[1] = (b*i+temp[0])/2;
        }
        if(n==a+1) {
            cout <<temp[1]%mod <<"\n";
        } else {
            // (a+2,a) - (n,a)
            for(int i=a+2;i<=n;i++) {
                
            }
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
