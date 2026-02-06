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

const int mxn=2e5;
int n,t;

int dist(pii a, pii b) {
    auto [r1,c1] = a;
    auto [r2, c2] = b;
    if((r1+c1)%2) {
        int ct0 = r2-r1 - (c2-c1);
        return (ct0+1)/2;
    } else {
        int ct0 = r2-r1 - (c2-c1);
        if(ct0==0) {
            return r2-r1;
        }
        return ct0/2;
    }
}

void solve() {
    cin >>n;
    vector<pii> v(n+1);
    v[0] = {1,1};
    rep(i,1,n+1) {
        cin >>v[i].fi;
    }
    rep(i,1,n+1) {
        cin >>v[i].se;
    }
    sort(all(v));
    ll ans = 0;
    rep(i,0,sz(v)-1) {
        if(v[i]==v[i+1]) continue;
        ans += dist(v[i],v[i+1]);
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