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
int n,k;
int ct1[mxn+1],ct2[mxn+1];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        int ai; cin >>ai;
        ct1[ai]++;
    }
    rep(i,0,n) {
        int bi; cin >>bi;
        ct2[bi]++;
    }
    int x = 0;
    rep(i,1,mxn+1) {
        max_self(x, (ct1[i]+ct2[i]-n));
    }
    if(x>k) {
        cout <<"Tidak\n";
    } else {
        cout <<"Ya\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}