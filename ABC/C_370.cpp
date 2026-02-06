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
int n;
string s,t;

void solve() {
    cin >>s >>t;
    n = sz(s);
    vi g,b;
    rep(i,0,n) {
        if(s[i]!=t[i]) {
            if(s[i]<t[i]) {
                b.push_back(i);
            } else {
                g.push_back(i);
            }
        }
    }
    vector<string> ans;
    rep(i,0,sz(g)) {
        s[g[i]] = t[g[i]];
        ans.push_back(s);
    }
    per(i,sz(b)-1,-1) {
        s[b[i]] = t[b[i]];
        ans.push_back(s);
    }
    cout <<sz(ans) <<"\n";
    for(auto st : ans) {
        cout <<st <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}