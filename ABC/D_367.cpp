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
int n,m;
int a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pr(n+1,0);
    rep(i,1,n+1) {
        pr[i] = pr[i-1]+a[i-1];
    }
    vector<ll> gr(m, 0);
    int r = pr[n]%m;
    ll ans = 0;
    rep(i,0,n+1) {
        ans += gr[pr[i]%m];
        int ir = pr[i]%m;
        int jr = (ir-r+m)%m;
        ans += gr[jr];
        gr[pr[i]%m]++;
    }
    rep(i,1,n+1) {
        if((pr[i]%m)==r) {
            ans--;
        }
    }
    rep(i,1,n) {
        if(((pr[n]-pr[i])%m)==r) {
            ans--;
        }
    }
    if(r==0) {
        ans--;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}