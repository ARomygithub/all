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

const int mxn=2e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    deque<int> dq;
    vector<int> b;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    for(auto bi: b) {
        dq.push_back(bi);
    }
    for(int l=0,r=n-1;l<=r;) {
        if(dq.front()==a[l]) {
            dq.pop_front();
            l++;
        } else if(dq.front()==a[r]) {
            dq.pop_front();
            r--;
        } else if(dq.back()==a[l]) {
            dq.pop_back();
            l++;
        } else if(dq.back()==a[r]) {
            dq.pop_back();
            r--;
        } else {
            cout <<l+1 <<" " <<r+1 <<"\n";
            return;
        }
    }
    cout <<"-1\n";
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