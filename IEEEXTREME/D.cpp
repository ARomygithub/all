#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n,m;
int ans[mxn][mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int x1,y1,x2,y2; cin >>x1 >>y1 >>x2 >>y2;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans[i][j] = (i+j)%2;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout <<ans[i][j] <<" \n"[j==n-1];
        }
        // cout <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}