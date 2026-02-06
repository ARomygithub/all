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
    vector<vector<int>> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        int k; cin >>k;
        v[i].resize(k);
        for(int j=0;j<k;j++) {
            cin >>v[i][j];
            mp[v[i][j]]++;
        }
    }
    for(int i=0;i<n;i++) {
        bool flag=0;
        for(int j=0;j<sz(v[i]);j++) {
            if(mp[v[i][j]]==1) {
                flag=1;
            }
        }
        if(!flag) {
            cout <<"Yes\n";
            return;
        }
    }
    cout <<"No\n";
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