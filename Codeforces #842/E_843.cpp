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
ll a[mxn+1];

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    vector<ll> dpc(n+1,0),dpb(n+1,0);
    dpc[0] = 0, dpb[0]=0;
    for(int i=1;i<=n;i++) {
        if(a[i]>0) {
            int temp = min(dpb[i-1],a[i]);
            dpb[i] = dpb[i-1], dpc[i]=dpc[i-1];
            dpb[i] -=temp;
            dpc[i] +=a[i];
        } else if(a[i]<0) {
            int temp = min(dpc[i-1],a[i]*(-1));
            dpb[i] = dpb[i-1], dpc[i]=dpc[i-1];
            dpc[i] -=temp;
            dpb[i] +=a[i]*(-1);
        } else {
            dpc[i] = dpc[i-1], dpb[i]=dpb[i-1];
        }
        // cout <<dpc[i]+dpb[i] <<"\n";
    }
    cout <<dpc[n]+dpb[n] <<"\n";
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