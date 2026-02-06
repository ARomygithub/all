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

const int mxn=1e5;
int n,q;

void solve() {
    cin >>n >>q;
    vector<bool> r(n,0),c(n,0);
    rep(i,0,n) {
        c[i] = (i%2)==0;
        r[i] = (i%2)==0;
    }
    int ctc=1,ctr=1;
    rep(i,1,n) {
        ctc += c[i]!=c[i-1];
        ctr += r[i]!=r[i-1];
    }
    rep(i,0,q) {
        string s; int x;
        cin >>s >>x; x--;
        if(s[0]=='R') {
            if(x>0) {
                ctr += r[x]==r[x-1]?1:-1;
            }
            if(x+1<n) {
                ctr += r[x]==r[x+1]?1:-1;
            }
            r[x] = !r[x];
        } else {
            if(x>0) {
                ctc += c[x]==c[x-1]?1:-1;
            }
            if(x+1<n) {
                ctc += c[x]==c[x+1]?1:-1;
            }
            c[x] = !c[x];
        }
        cout <<1ll*ctc*ctr <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}