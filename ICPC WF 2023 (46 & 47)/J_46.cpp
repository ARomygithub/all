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
int n;
string s;

void solve() {
    cin >>s;
    string ans = "";
    rep(i,0,sz(s)) {
        if(i==0 || (s[i]!=ans[sz(ans)-1])) {
            ans += s[i];
        }
    }
    // cout <<ans <<"\n";
    if(sz(ans)<=3) {
        cout <<ans <<"\n";
        return;
    }
    if(sz(ans)%2) {
        cout <<ans.substr(0,3) <<"\n";
    } else {
        cout <<ans.substr(0,2) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}