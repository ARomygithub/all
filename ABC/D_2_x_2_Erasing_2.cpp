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

const int mxn=1e5, inf = 100;
int n,m,t;

bool cek(int x) {
    rep(i,0,m-1) {
        if(((x>>i)&1) && ((x>>(i+1))&1)) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >>n >>m;
    vi st(n,0);
    rep(i,0,n) {
        string s; cin >>s;
        int sti = 0;
        rep(j,0,m) {
            if(s[j]=='#') {
                sti += (1<<j);
            }
        }
        st[i] = sti;
    }
    vi dp((1<<m),inf);
    rep(bit,0,(1<<m)) {
        if((st[0]|bit) == st[0]) {
            dp[bit] = __builtin_popcount(bit^st[0]);
        }
    }
    rep(i,1,n) {
        vi dp_new((1<<m),inf);
        rep(bit0,0,(1<<m)) {
            rep(bit1,0,(1<<m)) {
                if(cek(bit0&bit1)) {
                    min_self(dp_new[bit1], dp[bit0]);
                }
            }
        }
        rep(bit,0,(1<<m)) {
            if(dp_new[bit]==inf) continue;
            if((st[i]|bit) == st[i]) {
                dp_new[bit] += __builtin_popcount(bit^st[i]);
            } else {
                dp_new[bit] = inf;
            }
        }
        dp.swap(dp_new);        
    }
    int ans = inf;
    rep(j,0,(1<<m)) {
        min_self(ans, dp[j]);
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