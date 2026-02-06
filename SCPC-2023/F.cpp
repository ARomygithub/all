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

const int mxn=1e5;
int n;
pii h[mxn];
int ord[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>h[i].fi;
        h[i].se = i;
    }
    if(n==1) {
        cout <<"Ya\n";
        return;
    }
    sort(h,h+n);
    for(int i=0;i<n;i++) {
        ord[i] = h[i].se;
    }
    bool asc = (ord[0]<ord[1]);
    int idx = 2;
    for(idx=2;idx<n;idx++) {
        if(asc) {
            if(ord[idx]<ord[idx-1]) {
                break;
            }
        } else {
            if(ord[idx]>ord[idx-1]) {
                break;
            }
        }
    }
    for(;idx<n;idx++) {
        if(asc) {
            if(idx+1<n && ord[idx]<ord[idx+1]) {
                break;
            }
        } else {
            if(idx+1<n && ord[idx]>ord[idx+1]) {
                break;
            }
        }
    }
    if(idx<n) {
        cout <<"Tidak\n";
    } else {
        cout <<"Ya\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}