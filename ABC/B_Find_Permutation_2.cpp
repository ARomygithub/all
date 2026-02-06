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
int n,t;
int ans[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>ans[i];
    }
    vector<bool> f(n+1,0);
    rep(i,0,n) {
        if(ans[i]>0) {
            f[ans[i]] = 1;
        }
    }
    rep(i,0,n) {
        if(ans[i]==-1) {
            rep(j,1,n+1) {
                if(!f[j]) {
                    f[j] = 1;
                    ans[i] = j;
                    break;
                }
            }
        }
    }
    rep(i,1,n+1) {
        if(!f[i]) {
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}