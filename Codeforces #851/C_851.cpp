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
    if(n%2) {
        vector<pii> ans(n);
        int x = (n*3+1)/2;
        for(int i=0,j=(n-1)/2;i<=j;i++,j--) {
            ans[i].fi = i+1;
            ans[i].se = x + j-i;
            ans[j].fi = j+1;
            ans[j].se = x - (j-i);
        }
        for(int i=(n+1)/2,j=n-1;i<=j;i++,j--) {
            ans[i].fi = i+1;
            ans[i].se = x + j-i;
            ans[j].fi = j+1;
            ans[j].se = x - (j-i);
        }
        cout <<"Yes\n";
        for(auto [a,b]: ans) {
            cout <<a <<" " <<b <<"\n";
        }
    } else {
        cout <<"No\n";
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