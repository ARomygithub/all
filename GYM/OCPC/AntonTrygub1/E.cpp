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
int n,a[mxn],t;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi pref(n,0);
    rep(i,0,n) {
        if(i>0) {
            pref[i] ^= pref[i-1];
        }
        pref[i] ^= a[i];
    }
    if(pref[n-1]) {
        cout <<"YES\n";
        cout <<"2\n";
        cout <<"1 1\n";
        cout <<"2 " <<n <<"\n";
    } else {
        pii ls = {-1,-1};
        rep(i,0,n) {
            if(pref[i]) {
                if(ls.fi==-1) {
                    ls = {pref[i],i};
                } else {
                    if(ls.fi!=pref[i]) {
                        cout <<"YES\n";
                        cout <<"3\n";
                        cout <<"1 " <<ls.se+1 <<"\n";
                        cout <<ls.se+2 <<" " <<i+1 <<"\n";
                        cout <<i+2 <<" " <<n <<"\n";
                        return;
                    }
                }
            }
        }
        cout <<"NO\n";
    }
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