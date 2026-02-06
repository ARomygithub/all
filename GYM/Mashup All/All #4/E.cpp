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

const int mxn=3e5;
int n,p,k;
int a[mxn];

void solve() {
    cin >>n >>p >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    map<int,int> mp;
    ll ans = 0;
    rep(i,0,n) {
        ll cur = 1ll*a[i]*a[i]%p;
        cur = cur*cur%p;
        cur = (cur - 1ll*k*a[i]%p + p)%p;
        int temp = cur;
        ans += mp[temp];
        mp[temp]++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}