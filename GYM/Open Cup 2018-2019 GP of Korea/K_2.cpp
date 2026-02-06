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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e3;
int n,q;
pii p[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>p[i].fi >>p[i].se;
    }
    while(q--) {
        pii u; cin >>u.fi >>u.se;
        vector<int> res;
        int mn=2e9;
        rep(i,0,n) {
            int temp = (u.fi-p[i].fi)*(u.fi-p[i].fi) + (u.se-p[i].se)*(u.se-p[i].se);
            if(temp<mn) {
                mn = temp;
                res.clear();
                res.push_back(i+1);
            } else if(temp==mn) {
                res.push_back(i+1);
            }
        }
        if(sz(res)==1) {
            cout <<"REGION " <<res[0] <<"\n";
        } else if(sz(res)==2) {
            cout <<"LINE " <<min(res[0],res[1]) <<" " <<max(res[0],res[1]) <<"\n";
        } else {
            cout <<"POINT\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}