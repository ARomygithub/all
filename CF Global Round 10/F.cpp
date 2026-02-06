#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n;
ll h[mxn];

void solve() {
    cin >>n;
    ll s = 0;
    ll cn2 = 0;
    rep(i,0,n) {
        cin >>h[i];
        s +=h[i];
        cn2 +=i;
    }
    ll k = (s-cn2)/n;
    ll dupli = k + (s-cn2)%n;
    vector<ll> ans;
    for(ll i=k+1;i<=dupli;i++) {
        ans.push_back(i);
    }
    ans.push_back(dupli);
    for(ll i=dupli+1;i<k+n;i++) {
        ans.push_back(i);
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}