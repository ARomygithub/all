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
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    ll ans = 0;
    rep(i,0,n) {
        rep(j,i,n) {
            string si = s.substr(i,j-i+1);
            vector<int> ct(sz(si),0);
            rep(k,0,sz(si)) {
                if(si[k]=='1') {
                    if((k>0 && ct[k-1]==1) || ct[k]==1) {
                        // nxt
                    } else {
                        if(k+1<sz(si)) {
                            ct[k+1] = 1;
                        } else {
                            ct[k] = 1;
                        }
                    }
                }
            }
            rep(k,0,sz(si)) {
                ans += ct[k];
            }
        }
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