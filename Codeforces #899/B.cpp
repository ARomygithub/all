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

const int mxn=50;
int n,t;

void solve() {
    cin >>n;
    vector<vector<int>> v(n);
    vector<set<int>> idx(mxn+1);
    for(int i=0;i<n;i++) {
        int k; cin >>k;
        v[i].resize(k);
        for(int j=0;j<k;j++) {
            cin >>v[i][j];
            idx[v[i][j]].insert(i);
        }
    }
    int ans=0;
    for(int i=1;i<=mxn;i++) {
        if(sz(idx[i])) {
            set<int> temp;
            for(int j=0;j<n;j++) {
                if(idx[i].find(j)==idx[i].end()) {
                    for(int k=0;k<sz(v[j]);k++) {
                        temp.insert(v[j][k]);
                    }
                }
            }
            max_self(ans, sz(temp));
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