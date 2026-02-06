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
int x,y,t;

void solve() {
    cin >>x >>y;
    int mx=1, nx=x;
    int my=1, ny=y;
    for(int i=2;i*i<=x;i++) {
        if((x%i)==0) {
            mx = x/i;
            nx = i;
        }
    }
    for(int i=2;i*i<=y;i++) {
        if((y%i)==0) {
            my = y/i;
            ny = i;
        }
    }
    int m = max(mx,my);
    for(int i=mx+1;i<=m;i++) {
        if((x%i)==0) {
            nx = x/i;
        }
    }
    for(int i=my+1;i<=m;i++) {
        if((y%i)==0) {
            ny = y/i;
        }
    }
    cout <<nx+ny+m-1 <<"\n";
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