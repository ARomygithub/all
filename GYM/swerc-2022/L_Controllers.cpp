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

void solve() {
    cin >>n;
    string ss;
    cin >>ss;
    int p=0,s=0;
    rep(i,0,n) {
        if(ss[i]=='+') {
            p++;
        } else {
            s++;
        }
    }
    int q; cin >>q;
    while(q--) {
        int a,b; cin >>a >>b;
        int d = __gcd(a,b);
        a /= d;
        b /= d;
        if(a<b) swap(a,b);
        int len = abs(p-s);
        if(a-b==0) {
            if(len==0) {
                cout <<"YES\n";
            } else {
                cout <<"NO\n";
            }
        } else {
            bool ok = 0;
            if((len % (a-b))==0) {
                int k = len / (a-b);
                if(1ll*a*k <= max(p,s)) {
                    ok = 1;
                }
            }
            if(ok) {
                cout <<"YES\n";
            } else {
                cout <<"NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}