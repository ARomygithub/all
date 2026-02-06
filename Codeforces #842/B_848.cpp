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
int n,m,d,t;
int a[mxn],p[mxn];

void solve() {
    cin >>n >>m >>d;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) {
        cin >>p[i];
        pos[p[i]] = i;
    }
    for(int i=0;i<m;i++) {
        cin >>a[i];
    }
    int ans = 1e9;
    for(int i=0;i+1<m;i++) {
        int temp = pos[a[i+1]]-pos[a[i]];
        if(temp<=0 || temp>d) {
            min_self(ans,0);
        } else {
            min_self(ans,temp);
            if(d+2<=n) {
                min_self(ans,min(temp,d+1-temp));
            }
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