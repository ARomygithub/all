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

const int mxn=5e3;
int n,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=0;i<n;i++) {
        cin >>b[i];
    }
    bool flag=1;
    for(int i=0;i<n&&flag;i++) {
        flag &=(a[i]==b[i]);
    }
    if(flag) {
        cout <<"Yes\n";
        return;
    }
    vector<pii> va,vb;
    for(int i=0;i<n;i++) {
        if(sz(va) && va.back().fi==a[i]) {
            va.back().se++;
        } else {
            va.push_back({a[i],1});
        }
    }
    if(sz(va)>1 && va.back().fi==va[0].fi) {
        va[0].se +=va.back().se;
        va.pop_back();
    }
    for(int i=0;i<n;i++) {
        if(sz(vb) && vb.back().fi==b[i]) {
            vb.back().se++;
        } else {
            vb.push_back({b[i],1});
        }
    }
    if(sz(vb)>1 && vb.back().fi==vb[0].fi) {
        vb[0].se +=vb.back().se;
        vb.pop_back();
    }
    for(int i=0;i<sz(va);i++) {
        int idx=0;
        int temp=0;
        for(int j=0;j<sz(va);j++) {
            if(idx<sz(vb) && va[(i+j)%sz(va)].fi == vb[idx].fi) {
                idx++;
                temp +=va[(i+j)%sz(va)].se-1;
            } else {
                temp +=va[(i+j)%sz(va)].se;
            }
        }
        if(idx==sz(vb)) {
            if(temp==0) {
                cout <<"No\n";
            } else {
                cout <<"Yes\n";
            }
            return;
        }
    }
    cout <<"No\n";
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