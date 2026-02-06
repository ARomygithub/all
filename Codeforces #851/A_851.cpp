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
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    int ct2=0;
    int ct2i=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        ct2 +=(a[i]==2);
    }
    int ans=-1;
    for(int i=0;i<n;i++) {
        ct2i +=(a[i]==2);
        if(ct2i*2==ct2) {
            cout <<i+1 <<"\n";
            return;
        }
    }
    cout <<ans <<"\n";
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