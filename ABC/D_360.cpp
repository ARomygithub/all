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

const int mxn=2e5;
int n,t;
string s;
int x[mxn];

void solve() {
    cin >>n >>t;
    cin >>s;
    rep(i,0,n) {
        cin >>x[i];
    }
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({x[i],i});
    }
    sort(v.begin(),v.end());
    queue<pii> l;
    ll ans = 0;
    rep(i,0,n) {
        int id = v[i].se, pos=v[i].fi;
        if(s[id]=='1') {
            l.push(v[i]);
        } else {
            while(sz(l) && t*2<pos-l.front().fi) {
                l.pop();
            }
            ans += sz(l);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}