#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

string s;

void solve() {
    cin >>s;
    vi ct(26,0);
    rep(i,0,sz(s)) {
        ct[s[i]-'a']++;
    }
    ll ans = 0;
    rep(i,0,26) {
        ans += 1ll*(ct[i])*(ct[i]+1)/2;
    }
    for(int i=0;i<sz(s);) {
        int j = i;
        while(j<sz(s) && s[j]==s[i]) {
            j++;
        }
        int len = j-i;
        ans -= 1ll*(len-1)*(len)/2;
        i = j;
    }
    ans++;
    cout <<ans <<"\n";
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}

/*
4
abaabc
qf
x
icpc
11
3
2
6
*/