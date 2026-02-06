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

const int mxa=1e3,mxk=100, lim=5e5;
const ll mxn = 1e14;
ll n,k;
ll e[mxk];
int sm[mxk+1][lim+1];

void init() {
    rep(j,1,lim+1) {
        sm[k][j] = 1;
    } 
    per(i,k-1,-1) {
        rep(j,0,lim+1) {
            sm[i][j] = sm[i+1][j];
        }
        for(int j = 0; j<lim+1;j+=e[i]) {
            sm[i][j] = 0;
        }
    }
    per(i,k,-1) {
        rep(j,0,lim) {
            sm[i][j+1] += sm[i][j];
        }
    }
}

ll dfs(ll val, int i) {
    if(i==k) {
        return val;
    }
    if(val<=lim) {
        return sm[i][val];
    }
    ll ret = 0;
    if(val >= e[i]) {
        ret -= dfs(val/e[i], i+1);
    }
    ret += dfs(val, i+1);
    return ret;
}

void solve() {
    cin >>n >>k;
    rep(i,0,k) {
        cin >>e[i];
        if(e[i]==1) {
            cout <<n <<"\n";
            return;
        }
    } 
    sort(e,e+k);
    init();
    ll ret = dfs(n,0);
    cout <<n-ret <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}