#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

string s;
int k;

void solve() {
    cin >>s;
    cin >>k;
    int n = sz(s);
    vector v(10,vi());
    rep(i,0,sz(s)) {
        v[s[i]-'0'].push_back(i);
    }
    int len = n-k;
    string ans = "";
    int le = 0;
    auto get0 = [&]() -> int {
        rep(i,0,10) {
            auto it = lower_bound(all(v[i]),le);
            if(it!=v[i].end() && (*it) <= n-len) {
                return (*it);
            }
        }
    };
    auto get1 = [&]() -> int {
        rep(i,1,10) {
            auto it = lower_bound(all(v[i]),le);
            if(it!=v[i].end() && (*it) <= n-len) {
                return (*it);
            }
        }
    };
    int ida = get1();
    ans += s[ida];
    le = ida+1;
    len--;
    while(len) {
        int id = get0();
        ans += s[id];
        le = id+1;
        len--;
    }
    cout <<ans <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}