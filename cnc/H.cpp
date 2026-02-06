#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n;
string s;

void solve() {
    cin >>s;
    vector<int> v;
    int ct=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='x') {
            v.push_back(i-ct);
            ct++;
        }
    }
    n = sz(v);
    sort(v.begin(),v.end());
    ll ans=0;
    ll mid=v[n/2];
    for(int i=0;i<n;i++) {
        ans +=abs(1ll*v[i]-mid);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}