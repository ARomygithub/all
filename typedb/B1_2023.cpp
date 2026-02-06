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
int n,t;

void solve() {
    cin >>n;
    int ans=0;
    vector<int> v;
    for(int i=2;1ll*i*i<=n;i++) {
        int idx=0;
        int ct=sz(v);
        while((n%i)==0) {
            n /=i;
            if(idx>=ct) {
                v.push_back(i);
            } else {
                v[idx] *=i;
            }
            idx++;
        }
    }
    if(n>1) {
        int ct=sz(v);
        if(0>=ct) {
            v.push_back(n);
        } else {
            v[0] *=n;
        }
    }
    for(auto vi: v) {
        ans +=vi;
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