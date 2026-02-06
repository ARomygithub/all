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

const int mxn=10;
int n,m;
set<int> s[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int c; cin >>c;
        for(int j=0;j<c;j++) {
            int a; cin >>a;
            s[i].insert(a);
        }
    }
    ll ans=0;
    for(int i=1;i<(1<<m);i++) {
        vector<bool> flag(n+1,0);
        for(int j=0;j<m;j++) {
            if((i>>j)&1) {
                for(auto si: s[j]) {
                    flag[si]=1;
                }
            }
        }
        flag[0] = 1;
        for(int j=1;j<=n;j++) {
            flag[0] =flag[0]&&flag[j];
        }
        if(flag[0]) ans++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}