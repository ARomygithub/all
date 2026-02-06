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

const int mxn=2e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> p(n,0);
    for(int i=2;i<n*2;i+=2) {
        p[i%n] = p[(i-2)%n] + a[(i-1)%n] - a[i%n];
    }
    ll smp = 0;
    rep(i,0,n) {
        smp += p[i];
    }
    if(smp%2) {
        // cout <<"-1\n";
        // return;
        rep(i,0,n) {
            p[i]++;
        }
        smp += n;
    }
    ll smv = smp/2;
    ll sm2 = 0;
    for(int i=0;i<n;i+=2) {
        sm2 += p[i];
    }
    vector<ll> v(n);
    v[0] = sm2 - smv;
    rep(i,1,n) {
        v[i] = p[i-1]-v[i-1];
    }
    ll mn = 1e18;
    rep(i,0,n) {
        min_self(mn, v[i]);
    }
    rep(i,0,n) {
        v[i] -= mn;
    }
    rep(i,0,n) {
        cout <<v[i] <<" \n"[i==n-1];
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