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
const ll mod= 1e9+7;
ll n;

vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> c(a.size(), vector<ll>(b[0].size(), 0));
    for(int i=0; i<a.size(); ++i) {
        for(int j=0; j<b[0].size(); ++j) {
            for(int k=0; k<a[0].size(); ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]%mod) % mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> matfastexpo(vector<vector<ll>> mat, ll b) {
    vector<vector<ll>> res(mat.size(), vector<ll>(mat.size(), 0));
    for(int i=0; i<mat.size(); ++i) {
        res[i][i] = 1;
    }
    while(b>0) {
        if(b&1) res = matmul(res, mat);
        mat = matmul(mat, mat);
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >>n;
    vector<vector<ll>> v = {{1},{1}};
    vector<vector<ll>> mat = {{1,1},{1,0}};
    vector<vector<ll>> res = matfastexpo(mat, n-1);
    vector<vector<ll>> ans = matmul(res, v);
    cout <<ans[0][0]*ans[0][0]%mod <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}