#include "bits/stdc++.h"
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

const int mxn=500;
int n;
int a[mxn];

void solve() {
    cin >>n;
    int s=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        s +=a[i];
    }
    // hrs even
    if(s%2) {
        cout <<"NO\n";
        return;
    }
    int s12 = 0;
    int s3 = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        if(a[i]==1 || a[i]==2) {
            s12 +=a[i];
        } else {
            s3 +=a[i];
            vector<int> v;
            v.push_back(a[i]);
            for(auto [k,va]: mp) {
                v.push_back(k+a[i]);
            }
            for(auto vi : v) {
                if(!mp.count(vi)) {
                    mp[vi] = 1;
                }
            }
        }
    }
    // int mid = s3/2;
    int mn=1e9;
    for(auto [k,va]: mp) {
        if(k<=s3-k) {
            min_self(mn,abs(s3-k*2));
        } else {
            break;
        }
    }
    if(s3==0) {
        mn=0;
    }
    // cout <<mn <<"\n";
    if(mn<=s12) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}