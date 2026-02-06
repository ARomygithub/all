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

const int mxn=50;
int n,t;
int a[mxn][mxn];

void solve() {
    cin >>n;
    int ti=1,tj=n*n;
    bool flag=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i%2==0) {
                if(flag) {
                    a[i][j] = ti;
                    ti++;
                } else {
                    a[i][j] = tj;
                    tj--;
                }
            } else {
                if(flag) {
                    a[i][n-1-j] = ti;
                    ti++;
                } else {
                    a[i][n-1-j] = tj;
                    tj--;
                }
            }
            flag ^=1;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j==0) {
                cout <<a[i][j];
            } else {
                cout <<" " <<a[i][j];
            }
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