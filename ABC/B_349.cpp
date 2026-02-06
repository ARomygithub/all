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

const int mxn=1e5;
int ct[26];
string s;

void solve() {
    cin >>s;
    rep(i,0,sz(s)) {
        ct[s[i]-'a']++;
    }
    map<int,int> mp;
    rep(i,0,26) {
        mp[ct[i]]++;
    }
    for(auto [k,v]: mp) {
        if(k!=0 && v!=2) {
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}