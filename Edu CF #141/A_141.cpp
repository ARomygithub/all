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

const int mxn=1e2;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    for(int  i=0;i<n;i++) {
        cin >>a[i];
    }
    sort(a,a+n,greater<int>());
    if(a[0]==a[n-1]) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
        cout <<a[n-1];
        for(int i=0;i<n-1;i++) {
            cout <<" " <<a[i];
        }
        cout <<"\n";
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