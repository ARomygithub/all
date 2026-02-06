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

const int mxn=1e3;
int n,m;
int sn[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>sn[i];
    }
    map<int,int> mp;
    for(int i=0;i<m;i++) {
        int s; cin >>s;
        mp[s]++;
    }
    int ct=0;
    for(int i=0;i<n;i++) {
        if(mp.count(sn[i]%1000)) {
            ct++;
        }
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}