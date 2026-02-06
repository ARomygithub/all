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
int n,k,t;
string a,b;

void solve() {
    cin >>n >>k;
    cin >>a >>b;
    vector<char> c;
    map<char,int> mpc;
    for(int i=0;i<n;i++) {
        if(!mpc.count(a[i])) {
            c.push_back(a[i]);
            mpc[a[i]] = 1;
        }
    }
    ll ans=0, temp=0;
    for(int i=0;i<n;i++) {
        if(a[i]==b[i]) {
            temp++;
            ans +=temp;
        } else {
            temp = 0;
        }
    }
    for(int i=1;i<(1<<sz(c));i++) {
        if(__builtin_popcount(i)>k) continue;
        temp = 0;
        set<char> sc;
        for(int j=0;j<sz(c);j++) {
            if((i>>j)&1) {
                sc.insert(c[j]);
            }
        }
        ll temp2=0;
        for(int j=0;j<n;j++) {
            if(a[j]==b[j] || (sc.find(a[j])!=sc.end())) {
                temp++;
                temp2 +=temp;
            } else {
                temp = 0;
            }
        }
        max_self(ans,temp2);
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