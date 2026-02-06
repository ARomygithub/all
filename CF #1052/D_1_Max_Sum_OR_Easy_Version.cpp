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
int l,r,t;

void solve() {
    cin >>l >>r;
    vi ans(r+1);
    function<void(int,int)> slv;
    ll sm = 0;
    slv = [&](int x, int ad) -> void {
        if(x==0) {
            ans[ad] = x;
            sm += (ad|x);
            return;
        }
        int pw = 31 - __builtin_clz(x);
        // cout <<x <<" " <<pw <<endl;
        int a1 = (1<<pw)-1;
        rep(i,0,(1<<pw)) {
            int cur = (a1^i);
            int cur2 = ((cur+(1<<pw))<=x? cur+(1<<pw): cur);
            ans[i+ad] = cur2;
            sm += (cur2 | (i+ad));
        }
        slv(x - (1<<pw), ad+(1<<pw));
    };
    slv(r,0);
    cout <<sm <<"\n";
    rep(i,0,r+1) {
        cout <<ans[i] <<" \n"[i==r];
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