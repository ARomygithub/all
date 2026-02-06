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

const int mxn=2e5;
const ll mod=998244353;
int n;
int a[mxn+1];

void solve() {
    cin >>n;
    set<int> calon;
    rep(i,1,n+1) {
        cin >>a[i];
        calon.insert(a[i]);
    }
    rep(i,1,n+1) {
        if(a[i]<i) {
            cout <<"0\n";
            return;
        }
    }
    for(auto c : calon) {
        if(a[c]!=c) {
            cout <<"0\n";
            return;
        }
    }
    map<int,int> mn;
    rep(i,1,n+1) {
        if(mn.count(a[i])) {
            min_self(mn[a[i]], i);
        } else {
            mn[a[i]] = i;
        }
    }
    vector<int> vmn;
    for(auto [key,val]: mn) {
        vmn.push_back(val);
    }
    sort(vmn.begin(),vmn.end());
    ll ans = 1;
    int ct=0;
    for(auto c : calon) {
        int len = upper_bound(vmn.begin(),vmn.end(),c)-vmn.begin();
        min_self(len,sz(vmn));
        int temp = len - ct;
        ans = ans*temp%mod;
        ct++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}