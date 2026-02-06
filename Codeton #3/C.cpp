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
int n,t;
string a,b;

void solve() {
    cin >>n;
    cin >>a;
    cin >>b;
    rep(i,1,n) {
        int v0 = (a[0]-'0')^(b[0]-'0');
        int v1 = (a[i]-'0')^(b[i]-'0');
        if(v0!=v1) {
            cout <<"NO\n";
            return;
        }
    }
    vector<pii> ans;
    per(i,n-1,1) {
        if(b[i]!=b[i-1]) {
            ans.push_back({0,i-1});
        }
    }
    int a0 = ((a[0]-'0')+(sz(ans)))%2;
    if(a0==(b[0]-'0')) {
        if(a0==1 && b[1]=='1') {
            // cout <<"TES" <<endl;
            ans.push_back({0,0});
            ans.push_back({1,n-1});
        } else if(a0==0 && b[1]=='1') {
            ans.push_back({0,0});
            ans.push_back({0,n-1});
        } else if(a0==1 && b[1]=='0') {
            ans.push_back({1,n-1});
            ans.push_back({0,n-1});
        }
    } else {
        if(a0==0 && b[1]=='0') {
            ans.push_back({1,n-1});
        } else if(a0==0 && b[1]=='1') {
            ans.push_back({0,0});
            ans.push_back({1,n-1});
            ans.push_back({0,n-1});
        } else if(a0==1 && b[1]=='0') {
            ans.push_back({0,n-1});
        } else {
            ans.push_back({0,0});
        }
    }
    cout <<"YES\n";
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi+1 <<" " <<ans[i].se+1 <<"\n";
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