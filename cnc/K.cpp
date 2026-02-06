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
ll n,t;

ll idx(ll x) {
    ll temp2 = 63-__builtin_clzll(x);
    // cout <<x <<" " <<temp2 <<"\n";
    return x-temp2-1;
}

void solve() {
    cin >>n;
    ll ans = n;
    while(true) {
        if(__builtin_popcountll(ans)<2) {
            ans++; continue;
        }
        ll temp = idx(ans);
        if(temp==n) {
            cout <<ans*2 <<"\n";
            return;
        } else {
            ans++;
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