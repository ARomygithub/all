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

const int mxn=5e4,mxm=10;
int n,m,t;
int a[mxn][mxm];

void solve() {
    cin >>n >>m;
    map<vector<int>,bool> mp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        map<int,int> mp2;
        for(int j=0;j<m;j++) {
            mp2[a[i][j]] = j+1;
        }
        vector<int> v;
        for(int j=1;j<=m;j++) {
            v.push_back(mp2[j]);
            mp[v] = 1;
        }
    }
    vector<int> ans(n,0);
    for(int i=0;i<n;i++) {
        vector<int> v;
        for(int j=0;j<m;j++) {
            v.push_back(a[i][j]);
            if(!mp[v]) {
                break;
            } else {
                ans[i]++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(i==0) {
            cout <<ans[i];
        } else {
            cout <<" " <<ans[i];
        }
    }
    cout <<"\n";
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