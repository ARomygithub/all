#include "bits/stdc++.h"
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
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    int ans=2;
    int temp=2;
    for(int i=2;i<n;i++) {
        if(i%2) {
            temp++;
            max_self(ans,temp);
        } else {
            if(abs(a[i]-a[i-2])<=2 && (a[i]%2)==(a[i-2])%2) {
                temp++;
                max_self(ans,temp);
            } else {
                temp = 2;
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}