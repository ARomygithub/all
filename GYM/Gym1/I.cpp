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

const int mxn=5e5;
ll n;
ll a[mxn], pref[mxn];

void solve() {
    cin >>n;
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        sum +=a[i];
    }
    sum /=n;
    map<ll,int> mp;
    int ans = 1;
    for(int i=0;i<n;i++) {
        a[i] -=sum;
        pref[i] = i>0?pref[i-1]+a[i]:a[i];
        mp[pref[i]]++;
    }
    max_self(ans,mp[0]);
    ll temp = pref[n-1];
    for(int i=0;i<n-1;i++) {
        temp +=a[i];
        mp[temp]++;
        mp[pref[i]]--;
        max_self(ans,mp[pref[i]]);
    }
    cout <<n-ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}