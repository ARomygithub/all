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
int a[mxn];

void solve() {
    cin >>n;
    int s=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        s +=a[i];
    }
    vector<int> v;
    for(int i=0;i+1<n;i++) {
        v.push_back(a[i]+a[i+1]);
    }
    sort(v.begin(),v.end());
    cout <<s-v[0]*2 <<"\n";
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