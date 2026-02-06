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

const int mxn=700;
int n;
int a[mxn];

using tp = tuple<int,int,int>;
void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector good(n, bitset<mxn>());
    vector can(n, vector(n, bitset<mxn>()));
    vector canLeft(n, bitset<mxn>());
    vector canRight(n, bitset<mxn>());
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            if(__gcd(a[i],a[j])>1) {
                good[i].set(j);
            }
        }
    }
    rep(i,0,n) {
        canLeft[i].set(i);
    }
    rep(i,0,n) {
        canRight[i].set(i);
    }
    rep(len,1,n+1) {
        rep(le,0,n-len+1) {
            int ri = le+len-1;
            can[le][ri] = canLeft[le] & canRight[ri];
            if(ri+1<n) {
                canLeft[le][ri+1] = (can[le][ri] & good[ri+1]).count()?1:0;
                // cout <<"ri+1" <<endl;
                // cout <<le <<" " <<ri+1 <<endl;
                // cout <<canLeft[le][ri+1] <<endl;
            }
            if(le-1>=0) {
                canRight[ri][le-1] = (can[le][ri] & good[le-1]).count()?1:0;
                // cout <<"le-1" <<endl;
                // cout <<le-1 <<" " <<ri <<endl;
                // cout <<canRight[ri][le-1] <<endl;
            }
        }
    }
    if(can[0][n-1].count()) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}