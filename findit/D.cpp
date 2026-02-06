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

const int mxn=1e3;
const ll mod=1e9+7;
int n;
int ct[mxn+1];

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        ct[i] = 0;
        for(int j=1;j<=9;j++) {
            if(i%j==0) ct[i]++;
        }
    }
    ll ans=1;
    for(int i=1;i<=n;i++) {
        ans = ans*ct[i]%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}
