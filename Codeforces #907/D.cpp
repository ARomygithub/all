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

const int mxn=1e5;
const ll mxa=1e18;
const ll mod=1e9+7;
int t;
ll l,r;
vector<ll> num[60];

void solve() {
    cin >>l >>r;
    ll ans=0;
    int fl = 63-__builtin_clzll(l);
    int fr = 63-__builtin_clzll(r);
    // cout <<fl <<" " <<fr <<"\n";
    for(ll i=fl;i<=fr;i++) {
        ll bwh = max(l,1ll<<i);
        ll atas = min(r,(1ll<<(i+1))-1);
        ll u = bwh;
        while(u<=atas) {
            auto it = upper_bound(num[i].begin(),num[i].end(),u);
            ll g = it-num[i].begin();
            ll knn =-1;
            if(it!=num[i].end()) {
                knn = (*it)-1;
            } else {
                knn = atas;
            }
            min_self(knn,atas);
            // cout <<g <<" " <<knn <<"\n";
            ans = (ans+g*(knn-u+1))%mod;
            u = knn+1;
        }
    }
    cout <<ans <<"\n";
    // cout <<num[59][9] <<"\n";
    // cout <<sz(num[59]) <<"\n";
}

void init() {
    rep(i,2,60) {
        for(ll u=i;u<=mxa;) {
            num[i].push_back(u);
            if(mxa/u >=i) {
                u *=i;
            } else {
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}