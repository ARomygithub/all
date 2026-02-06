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

const int mxn=3e5;
int n,q;
string s;
int pref[mxn+1];

void solve() {
    cin >>n >>q;
    cin >>s;
    rep(i,0,n) {
        if(i+1<n && s[i]==s[i+1]) {
            pref[i+1]++;
        }
    }
    rep(i,1,n+1) {
        pref[i] +=pref[i-1];
    }
    rep(i,0,q) {
        int l,r; cin >>l >>r;
        cout <<pref[r-1]-pref[l-1] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}