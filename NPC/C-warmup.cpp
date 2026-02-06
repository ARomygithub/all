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
int n,m;

void solve() {
    cin >>n >>m;
    vector<vector<ll>> sum(n+1,vector<ll>(m+1,0ll));
    ll sumAll = 0;
    int ct = 0;
    for(int i=1;i<=n;i++) {
        ll temp = 0;
        for(int j=1;j<=m;j++) {
            int ai; cin >>ai;
            temp +=ai;
            sumAll +=ai;
            if(ai!=0) ct++;
            sum[i][j] = temp+sum[i-1][j];
        }
    }
    ll ans = 1e18;
    for(int i=1;i<=min(n,m);i++) {
        int ni,mi;
        if(n<=m) {
            ni = i;
            if((ct%i)!=0 || (ct/i)>m) {
                continue;
            }
            mi = ct/i;
        } else {
            mi = i;
            if((ct%i)!=0 || (ct/i)>n) {
                continue;
            }
            ni = ct/i;
        }
        for(int j=1;j+ni-1<=n;j++) {
            for(int k=1;k+mi-1<=m;k++) {
                ll temp = sum[j+ni-1][k+mi-1]-sum[j+ni-1][k-1]-sum[j-1][k+mi-1]+sum[j-1][k-1];
                min_self(ans,sumAll-temp);
            }
        }
    }
    if(ans==1e18) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}