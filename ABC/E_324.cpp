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

const int mxn=5e5;
int n;
string t, s[mxn];

void solve() {
    cin >>n;
    cin >>t;
    for(int i=0;i<n;i++) {
        cin >>s[i];
    }
    vector<ll> pref(sz(t)+1,0), suf(sz(t)+1,0);
    for(int i=0;i<n;i++) {
        int idx=0;
        for(int j=0;j<sz(s[i])&&idx<sz(t);j++) {
            if(s[i][j]==t[idx]) {
                idx++;
            }
        }
        pref[idx]++;
        idx = sz(t)-1;
        for(int j=sz(s[i])-1;j>=0&&idx>=0;j--) {
            if(s[i][j]==t[idx]) {
                idx--;
            }
        }
        suf[sz(t)-1-idx]++;
    }
    for(int i=sz(t)-1;i>=0;i--) {
        pref[i] +=pref[i+1];
    }
    ll ans=0;
    for(int i=0;i<=sz(t);i++) {
        ans +=suf[i]*pref[sz(t)-i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}