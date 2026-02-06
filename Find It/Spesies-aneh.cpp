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
int x,y,n;

void solve() {
    cin >>x;
    vector<int> c;
    for(int i=0;i<x;i++) {
        cin >>y >>n;
        c.resize(n);
        for(int j=0;j<n;j++) {
            cin >>c[j];
        }
    }
    int ans = 1;
    for(int j=0;j<n;j++) {
        ans = ans*c[j]/__gcd(ans,c[j]);
    }
    ans +=y;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}