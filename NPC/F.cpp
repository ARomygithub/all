#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e2;
int n;
string s[mxn];
vector<ll> v[mxn];
ll ans[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>s[i];
        int m; cin >>m;
        v[i].resize(m);
        for(int j=0;j<m;j++) {
            cin >>v[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        ll mn=0,pref=0;
        for(int j=0;j<sz(v[i]);j++) {
            pref +=v[i][j];
            max_self(ans[i],pref-mn);
            min_self(mn, pref);
        }
    }
    string sans=s[0];
    ll ansi=ans[0];
    for(int i=1;i<n;i++) {
        if(ans[i]>ansi) {
            ansi = ans[i];
            sans = s[i];
        }
    }
    cout <<sans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}