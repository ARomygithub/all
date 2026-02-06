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

const int mxn=5e5;
int n,k,q;
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    cin >>q;
    map<ll,ll> mp;
    vector<ll> pr(n+1,0);
    rep(i,1,n+1) {
        pr[i] = pr[i-1] + a[i-1];
    }
    rep(i,0,n+1) {
        mp[pr[i]-1ll*k*i]++;
    }
    ll ans = 0;
    for(auto& [ke,v]: mp) {
        ans += v*(v-1)/2;
    }
    cout <<ans <<"\n";
    auto del = [&](ll x) -> void {
        ans -= (mp[x]*(mp[x]-1))/2;
        mp[x]--;
        ans += (mp[x]*(mp[x]-1))/2;
    };
    auto ad = [&](ll x) -> void {
        ans -= mp[x]*(mp[x]-1)/2;
        mp[x]++;
        ans += mp[x]*(mp[x]-1)/2;
    };
    while(q--) {
        char qt; cin >>qt;
        ll j,x; cin >>j >>x;
        if(qt=='L') {
            del(pr[j-1]-1ll*(j-1)*k);
            pr[j-1] += x;
            ad(pr[j-1]-1ll*(j-1)*k);
        } else {
            del(pr[j]-1ll*j*k);
            pr[j] -= x;
            ad(pr[j]-1ll*j*k);
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}