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

const int mxn=1e2;
int n,t;
ll x[mxn],y[mxn];

ll ask(char c, ll k) {
    cout <<"? " <<c <<" " <<k <<"\n" <<flush;
    ll ret; cin >>ret;
    if(ret==-1) exit(0);
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    ll ad = -2e9, mn = -2e9;
    rep(i,0,n) {
        max_self(ad, x[i]+y[i]);
        max_self(mn, y[i]-x[i]);
    } 
    ask('U', 1e9);
    ask('U', 1e9);
    ask('R', 1e9);
    ll qad = ask('R', 1e9);
    ask('L', 1e9);
    ask('L', 1e9);
    ask('L', 1e9);
    ll qmn = ask('L',1e9);
    ll ipj = qad + ad - (ll)(4e9);
    ll jmi = qmn + mn - (ll)(4e9);
    ll j = (ipj+jmi)/2;
    ll i = ipj - j;
    cout <<"! " <<i <<" " <<j <<"\n" <<flush;
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