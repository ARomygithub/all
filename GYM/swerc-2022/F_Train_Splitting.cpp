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

const int mxn=50*25;
int n,m,t;
pii e[mxn];

void solve() {
    cin >>n >>m;
    map<int,int> mp;
    rep(i,0,m) {
        cin >>e[i].fi >>e[i].se;
        mp[e[i].fi]++;
        mp[e[i].se]++;
    }
    int u = 1;
    while(mp[u]==n-1) {
        u++;
    }
    if(u<=n) {
        cout <<"2\n";
        rep(i,0,m) {
            if(e[i].fi==u || e[i].se==u) {
                cout <<"1" <<" \n"[i==m-1];
            } else {
                cout <<"2" <<" \n"[i==m-1];
            }
        }
        return;
    }
    cout <<"3\n";
    u = 1;
    rep(i,0,m) {
        if(e[i].fi==u || e[i].se==u) {
            if(e[i].fi+e[i].se==3) {
                cout <<"1" <<" \n"[i==m-1];
            } else {
                cout <<"2" <<" \n"[i==m-1];
            }
        } else {
            cout <<"3" <<" \n"[i==m-1];
        }
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