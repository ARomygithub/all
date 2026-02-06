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
int n,x,y,t;

void solve() {
    cin >>x >>y;
    vector<int> ans;
    int u = x;
    while(u>=y) {
        ans.push_back(u);
        u--;
    }
    u = y+1;
    while(u<x) {
        ans.push_back(u);
        u++;
    }
    cout <<sz(ans) <<"\n";
    for(int i=0;i<sz(ans);i++) {
        if(i==0) {
            cout <<ans[i];
        } else {
            cout <<" " <<ans[i];
        }
    }
    cout <<"\n";
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