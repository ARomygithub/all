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
int len[mxn];

void solve() {
    cin >>n >>m;
    int mx=-1;
    for(int i=0;i<n;i++) {
        cin >>len[i];
        max_self(mx, len[i]);
    }
    ll ans=1e18;
    ll l=mx, r=3e14;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll temp=0;
        ll leni=0;
        for(int i=0;i<n;i++) {
            if(leni==0) {
                leni +=len[i];
                temp++;
            } else {
                if(len[i]+1<=mid-leni) {
                    leni +=len[i]+1;
                } else {
                    temp++;
                    leni = len[i];
                }
            }
        }
        if(temp<=m) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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