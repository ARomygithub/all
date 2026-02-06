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

const int mxn=1e5;
int n,t;

void solve() {
    cin >>n;
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        int x; cin >>x;
        mp[x]++;
    }
    ll ans=0;
    for(auto [k,v]: mp) {
        ans +=1ll*v*(v-1)*(v-2);
        for(int i=2;i*i<=k;i++) {
            if(k%(i*i)==0) {
                ans += 1ll*v*mp[k/i]*mp[k/(i*i)];
            }
        }
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