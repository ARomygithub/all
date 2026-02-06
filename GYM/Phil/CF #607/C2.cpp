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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5,mxl=1e6;
const ll mod=1e9+7;
ll n,x,t;

void solve() {
    string s;
    cin >>x;
    cin >>s;
    n = s.length();
    ll l=0;
    rep(i,0,x) {
        l++;
        int ct = s[l-1]-'0';
        int rl = n-l;
        if(sz(s)<x) {
            string suf = s.substr(n-rl,rl);
            rep(j,0,ct-1) {
                s +=suf;
            }
        }
        rl %=mod;
        rl = (rl+mod)%mod;
        n = (n+rl*(ct-1))%mod;
    }
    cout <<n <<"\n";
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