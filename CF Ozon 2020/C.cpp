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

const int mxm=1e3;
int n,m;
ll ct[mxm];

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%m;
        a = a*a%m;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    vector<int> v;
    rep(i,0,n) {
        int ai; cin >>ai;
        v.push_back(ai);
    }
    sort(v.begin(),v.end());
    rep(i,0,n) {
        int ai = v[i];
        ai %=m;
        ct[ai]++;
    }
    ll ans = 1ll;
    rep(i,0,m) {
        if(ct[i]>=2) {
            cout <<"0\n";
            return;
        }
    }
    rep(i,0,n) {
        rep(j,i+1,n) {
            ll temp =  (v[j]-v[i])%m;
            ans = (ans*temp)%m;
            // cout <<i <<" " <<j <<"\n";
            // cout <<ans <<"\n";
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}