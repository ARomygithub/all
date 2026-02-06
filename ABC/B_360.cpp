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
int n,m;
string s,t;

void solve() {
    cin >>s >>t;
    n = sz(s), m = sz(t);
    rep(w,1,sz(s)) {
        int len = (n/w);
        rep(c,1,w+1) {
            int leni = len + ((n%w)>=c);
            if(leni!=m) continue;
            rep(j,0,m) {
                if(s[j*w+c-1]!=t[j]) {
                    break;
                }
                if(j==m-1) {
                    cout <<"Yes\n";
                    return;
                }
            }
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}