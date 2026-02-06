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
ll n,x,y;
ll ans[mxn];

void solve() {
    cin >>n >>x >>y;
    if(x+y>n+1) {
        cout <<"-1\n";
        return;
    }
    if(x*y<n) {
        cout <<"-1\n";
        return;
    }
    if(x==1 && y==n) {
        iota(ans,ans+n,1);
        sort(ans,ans+n,greater<ll>());
        for(int i=0;i<n;i++) {
            if(i==0) {
                cout <<ans[i];
            } else {
                cout <<" " <<ans[i];
            }
        }
        cout <<"\n";
        return;
    }
    if(x==n && y==1) {
        iota(ans,ans+n,1);
        for(int i=0;i<n;i++) {
            if(i==0) {
                cout <<ans[i];
            } else {
                cout <<" " <<ans[i];
            }
        }
        cout <<"\n";
        return;        
    }
    iota(ans,ans+n,1);
    sort(ans+n-y,ans+n,greater<ll>());
    sort(ans,ans+n-y,greater<ll>());
    for(int i=0;i<n-y;i+=x-1) {
        ll temp = min(i+x-1,n-y);
        sort(ans+i,ans+temp);
    }
    for(int i=0;i<n;i++) {
        if(i==0) {
            cout <<ans[i];
        } else {
            cout <<" " <<ans[i];
        }
    }
    cout <<"\n";
    return;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}