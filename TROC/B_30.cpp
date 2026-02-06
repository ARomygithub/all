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
int n;
int a[mxn], b[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int j=0;j<n;j++) {
        cin >>b[j];
    }
    int j=0;
    for(int i=0;i<n&&j<n;i++) {
        while(j<n && a[i]==b[j]) {
            j++;
        }
    }
    if(j==n) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}