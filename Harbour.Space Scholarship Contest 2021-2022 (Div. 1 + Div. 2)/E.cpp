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

const int mxn=3e5;
int n,m,t;
int p[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>p[i]; p[i]--;
    }
    vector<int> ct(n,0);
    rep(i,0,n) {
        int r = (i-p[i]+n)%n;
        // if(i>=r) {
        ct[r]++;
        // }
    }
    vector<int> ans;
    rep(i,0,n) {
        // cout <<ct[i] <<" \n"[i==n-1];
        if(ct[i]>=n-m*2) {
            int ctswap = 0;
            vector<int> v(n),pos(n);
            rep(j,0,i) {
                v[j] = n-i+j;
                pos[n-i+j] = j;
            }
            rep(j,i,n) {
                v[j] = j-i;
                pos[j-i] = j;
            }
            rep(j,0,n) {
                if(v[j]!=p[j]) {
                    int j2 = pos[p[j]];
                    swap(v[j],v[j2]);
                    swap(pos[v[j2]],pos[v[j]]);
                    ctswap++;
                }
            }
            if(ctswap<=m) {
                ans.push_back(i);
            }
        }
    }
    cout <<sz(ans) <<" \n"[sz(ans)==0];
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
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