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

const int mxn=5e5;
int t;
string s,x,y;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>s;
    cin >>x;
    cin >>y;
    vector<int> ctx(2,0), cty(2,0);
    rep(i,0,sz(x)) {
        ctx[x[i]-'0']++;
    }
    rep(i,0,sz(y)) {
        cty[y[i]-'0']++;
    }
    if(cty[1]==ctx[1]) {
        if(ctx[0]!=cty[0]) {
            cout <<"No\n";
        } else {
            cout <<"Yes\n";
        }
        return;
    }
    int xy = ctx[0]-cty[0];
    int yx = cty[1]-ctx[1];
    if((1ll*xy*sz(s))%yx) {
        cout <<"No\n";
        return;
    }
    ll len = (1ll*xy*sz(s))/yx;
    if(len<0) {
        cout <<"No\n";
        return;
    }  else if(len==0) {
        cout <<"Yes\n";
        return;
    }
    ll d = __gcd(len, 1ll*sz(s));
    bool ok = 1;
    rep(i,d,sz(s)) {
        ok = ok&& (s[i]==s[i-d]);
    }
    if(ok) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
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