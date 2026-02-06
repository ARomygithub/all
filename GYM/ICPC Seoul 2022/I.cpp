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

const int mxn=1e5;
string s;

int min_dp(int l, int r, int bts) {
    if(r<=l) return 0;
    if(s[l]==s[r]) {
        return min_dp(l+1,r-1,bts);
    }
    if(bts==0) return -1;
    int le = min_dp(l+1,r,bts-1);
    int ri = min_dp(l,r-1,bts-1);
    int ret = 1e9;
    if(le!=-1) {
        min_self(ret, le+1);
    }
    if(ri!=-1) {
        min_self(ret, ri+1);
    }
    if(ret==1e9) {
        ret = -1;
    }
    return ret;
}

void solve() {
    cin >>s;
    cout <<min_dp(0,sz(s)-1,3) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}