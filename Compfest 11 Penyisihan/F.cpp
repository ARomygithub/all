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
typedef pair<char,string> pcs;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
int n,m;
string s;

void solve() {
    cin >>n >>m;
    cin >>s;
    vector<pcs> v;
    rep(i,0,m) {
        char c; string s1; cin >>c >>s1;
        v.push_back({c,s1});
    }
    vector<ll> ct(26,0);
    rep(i,0,sz(s)) {
        ct[s[i]-'A']++;
    }
    rep(i,0,m) {
        ll tmp = ct[v[i].fi-'A'];
        ct[v[i].fi-'A'] = 0;
        rep(j,0,sz(v[i].se)) {
            ct[v[i].se[j] - 'A'] += tmp;
        }
    }
    ll ans = 0;
    rep(i,0,26) {
        ans += ct[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}