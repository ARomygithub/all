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

const int mxn=50;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int idx = n-1;
    int last = 100;
    while(idx>=0 && a[idx]<=last && a[idx]>=10) {
        last = a[idx];
        idx--;
    }
    bool ok = 1;
    while(idx>=0) {
        string s = to_string(a[idx]);
        per(j,sz(s)-1,-1) {
            if(s[j]-'0' > last) {
                ok = 0;
                break;
            }
            last = s[j]-'0';
        }
        if(!ok) break;
        idx--;
    }
    if(ok && idx<0) {
        cout <<"YES\n";
    } else {
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