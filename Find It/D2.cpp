#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int x,y,t;

void solve() {
    cin >>x >>y;
    ll ans=1e18;
    // for(int i=1;((i-1)*(i-1)<=x)||((i-1)*(i-1)<=y);i++) {
    //     ll temp = 1ll*(x+i-1)/i + (y+i-1)/i + i - 1;
    //     min_self(ans, temp);
    // }
    // int ix = x, iy= y;
    // for(int i=1;(i*i<=x);i++) {
    //     if((x%i)==0) {
    //         ix = x/i;
    //     }
    // }
    // for(int i=1;i*i<=y;i++) {
    //     if((y%i)==0) {
    //         iy = y/i;
    //     }
    // }
    for(int i=1;i<=max(x,y);i++) {
        ll temp = 1ll*(x+i-1)/i + (y+i-1)/i + i - 1;
        min_self(ans, temp);
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