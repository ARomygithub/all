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

const int mxn=2e5;
int n,m;
int h[mxn+2],c[mxn+1];

void solve() {
    cin >>n >>m;
    for(int i=1;i<=n;i++) {
        cin >>h[i];
    }
    h[0] = 200000, h[n+1]=200000;
    int l=m,r=m+1;
    ll ans=0;
    int cc=0;
    // if(h[l]<h[r]) {
    //     ans +=h[l];
    //     cc = h[l];
    //     l--;
    // } else if(h[l]==h[r]) {
    //     ans +=h[l]-cc;
    //     cc = h[l];
    //     l--,r++;
    // } else {
    //     ans +=h[r];
    //     cc = h[r];
    //     r++;
    // }    
    while(true) {
        ll temp1=0,temp2=0;
        while(l>=0 && h[l]<=cc) {
            temp1 +=h[l];
            l--;
        }
        if(l>=0) {
            temp1 +=cc-c[l];
        }
        while(r<=n+1 && h[r]<=cc) {
            temp2 +=h[r];
            r++;
        }
        if(r<=n+1) {
            temp2 +=cc-c[r-1];
        }
        ans +=max(temp1,temp2);
        if(l<0 || r>n+1) break;
        // cout <<h[l] <<" " <<h[r] <<"\n";
        if(h[l]<h[r]) {
            ans +=h[l]-cc;
            cc = h[l];
            c[l] = cc;
            c[r-1] = cc;
            l--;
        } else if(h[l]==h[r]) {
            ans +=h[l]-cc;
            cc = h[l];
            c[l] = cc;
            c[r-1] = cc;
            l--,r++;
        } else {
            ans +=h[r]-cc;
            cc = h[r];
            c[l] = cc;
            c[r-1] = cc;
            r++;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}