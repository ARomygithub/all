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

const int mxn=500;
int t;
string s1,s2;

void solve() {
    cin >>s1;
    cin >>s2;
    rep(l,0,sz(s2)) {
        bool ok = 1;
        rep(i,0,l) {
            if(l*2-i >= sz(s2)) continue;
            if(s2[i]!=s2[l*2-i]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            string sub = "";
            per(i,sz(s2)-1,l*2) {
                sub += s2[i];
            }
            rep(i,0,l+1) {
                sub += s2[i];
            }
            rep(i,0,sz(s1)) {
                if(i+sz(sub) > sz(s1)) break;
                bool ok2 = 1;
                rep(j,0,sz(sub)) {
                    if(sub[j]!=s1[i+j]) {
                        ok2 = 0;
                        break;
                    }
                }
                if(ok2) {
                    cout <<"YES\n";
                    return;
                }
            }
        }
    }

    cout <<"NO\n";
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