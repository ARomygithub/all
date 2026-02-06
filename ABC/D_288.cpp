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

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector diff(n, vector<ll>(k,0));
    rep(i,0,n) {
        if(i>0) {
            rep(j,0,k) {
                diff[i][j] = diff[i-1][j];
            }
        }
        diff[i][i%k] += a[i]-(i>0?a[i-1]:0);
        // cout <<diff[i][i%k] <<"\n";
    }
    cin >>q;
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        int cur = r%k;
        bool ok = 1;
        rep(i,0,k-1) {
            int curi = (cur-i+k)%k;
            // ll tes = 0;
            // for(int j=r-i;j>=l;j-=k) {
            //     tes += (a[j]-(j>0?a[j-1]:0ll));
            // }
            ll temp = diff[r][curi] - (l>0?diff[l-1][curi]:0ll);
            if(curi==(l%k)) {
                temp += (l>0?a[l-1]:0ll);
            }
            // assert(temp==tes);
            if(temp!=0) {
                ok = 0;
                break;
            }
        }
        if(ok) {
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