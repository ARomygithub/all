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

const int mxn=2e5;
int n,t;
string s;

void solve() {
    cin >>s;
    int ct = 0, ans = 0;
    rep(i,0,sz(s)-1) {
        if(i==0 || s[i-1]=='u') {
            if(s[i]=='u') {
                ans++;
                s[i] = 's';
            }
        }
        ct += s[i]=='s';
    }
    if(s[sz(s)-1]=='u') {
        ans++;
        s[sz(s)-1] = 's';
    }
    ct++;
    if(ct<2) {
        ans += 2-ct;
    }
    cout <<ans <<"\n";
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