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
int n,p,q,r,s;
int a[mxn+1];

void solve() {
    cin >>n >>p >>q >>r >>s;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    for(int i=p,j=r;i<=q;i++,j++) {
        swap(a[i],a[j]);
    }
    for(int i=1;i<=n;i++) {
        if(i==1) {
            cout <<a[i];
        } else {
            cout <<" " <<a[i];
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}