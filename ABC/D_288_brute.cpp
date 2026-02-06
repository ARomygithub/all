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

const int mxn=2e5;
int n,k,q;
ll a[mxn];

bool check(int l, int r) {
    vector<ll> now(n,0);
    rep(i,l,r-k+2) {
        ll diff = a[i]-(i>l?a[i-1]:0ll);
        now[i] = (i-k>=0?now[i-k]:0ll) + diff;
        // cout <<now[i] <<" ";
    } 
    rep(i,r-k+2,r+1) {
        ll temp = 0;
        per(j,i,max(-1,i-k)) {
            temp += now[j];
        }
        if(temp!=a[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    cin >>q;
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        if(check(l,r)) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}