#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e2, mxh=1e3;
bool flag[mxn];
int a[mxn];
set<int> h[mxh+1];
string s;

void solve() {
    // char c; cin >>c;
    getline(cin,s);
    stringstream ss(s);
    int n = 0; int hi;
    while(ss >> hi) {
        h[hi].insert(n);
        a[n] = hi;
        flag[n] = 0;
        n++;
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        if(!flag[i]) {
            ans++;
            flag[i]=1;
            h[a[i]].erase(i);
            for(int j=a[i]-1, idx=i;j>=1;j--) {
                auto it = h[j].lower_bound(idx);
                if(it!=h[j].end()) {
                    flag[*it] = 1;
                    idx = *it;
                    h[j].erase(it);
                } else {
                    break;
                }
            }
        }
    }
    cout <<ans <<endl;
    // char c; cin >>c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    getline(cin,s);
    stringstream s1(s);
    int t; s1 >>t;
    while(t--) {
        solve();
    }
}
