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
int n,q;
string s;

void solve() {
    cin >>n;
    cin >>s;
    cin >>q;
    vector st(26, set<char>());
    rep(i,0,26) {
        st[i].insert((char)('a'+i));
    }
    while(q--) {
        char c,d; cin >>c >>d;
        for(auto v : st[c-'a']) {
            st[d-'a'].insert(v);
        }
        if(c!=d) {
            st[c-'a'].clear();
        }
    }
    map<char,char> mp;
    rep(i,0,26) {
        for(auto v: st[i]) {
            mp[v] = (char)('a'+i);
        }
    }
    rep(i,0,n) {
        cout <<mp[s[i]];
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}