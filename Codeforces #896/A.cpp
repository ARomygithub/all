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

const int mxn=1e5;
int n,m,t;

void solve() {
    cin >>n >>m;
    if(m==1) {
        cout <<"0\n";
        for(int i=0;i<n;i++) {
            cout <<"0\n";
        }
        return;
    }
    int ans = min(n+1,m);
    cout <<ans <<"\n";
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<ans-1;i++) {
        int st0=i+1;
        for(int j=0;j<m;j++) {
            v[i][(st0+j)%m] = j;
        }
    }
    for(int i=ans-1;i<n;i++) {
        for(int j=0;j<m;j++) {
            v[i][(j+1)%m] = j;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(j==0) {
                cout <<v[i][j];
            } else {
                cout <<" " <<v[i][j];
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