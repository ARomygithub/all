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

const int mxn=2e3;
int n,m,t;
int c[mxn],a[mxn];

void solve() {
    cin >>n >>m;
    vector<int> ct(n+1,0);
    for(int i=0;i<n;i++) {
        cin >>a[i];
        ct[a[i]]++;
    }
    for(int i=0;i<m;i++) {
        cin >>c[i];
    }
    sort(c,c+m,greater<int>());
    priority_queue<int> pq;
    int ans=0;
    for(int i=1;i<=n;i++) {
        pq.push(ct[i]);
    }
    for(int i=0;i<m;i++) {
        if(!sz(pq)) break;
        int u = pq.top(); pq.pop();
        if(c[i]>=u) {
            ans +=u;
        } else {
            ans +=c[i];
            pq.push(u-c[i]);
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