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

const int mxn=5e5;
int n,m,t;
int a[mxn];

void solve() {
    cin >>n >>m;
    vector<int> v(n);
    set<int> s;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        v[i] = a[i];
    }
    sort(v.begin(),v.end());
    int k=0;
    while(k<n && m>=v[k]) {
        m -=v[k];
        s.insert(v[k]);
        k++;
    }
    if(k==n || s.find(a[k])!=s.end()) {
        cout <<max(n-k,1) <<"\n";
    } else {
        if(k-1>=0 && m+v[k-1]>=a[k]) {
            cout <<max(n-k,1) <<"\n";
        } else {
            cout <<n-k+1 <<"\n";
            assert(n-k!=0);
        }
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