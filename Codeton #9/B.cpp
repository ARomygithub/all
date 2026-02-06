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

const int mxn=1e5;
int t;
string s;

void solve() {
    cin >>s;
    rep(i,0,sz(s)-1) {
        if(s[i]==s[i+1]) {
            cout <<s.substr(i,2) <<"\n";
            return;
        }
    }
    rep(i,0,sz(s)-2) {
        if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]) {
            cout <<s.substr(i,3) <<"\n";
            return;
        }
    }
    cout <<"-1\n";
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