#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m,t;
int a[mxn],b[mxn];
ll x,k,y;

void solve() {
    cin >>n >>m;
    cin >>x >>k >>y;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    ll ans = 0;
    int j = 0;
    int l1 = -1;
    rep(i,0,n) {
        if(j<m && a[i]==b[j]) {
            int len = i-l1-1;
            int mx = 0;
            rep(i2,l1+1,i) {
                max_self(mx, a[i2]);
            }
            if(x <= k*y) {
                if(len>=1 && len<k) {
                    if((l1>=0 && a[l1]>mx) || (i<n && a[i]>mx)) {
                        ans += y*len;
                    } else {
                        cout <<"-1\n";
                        return;
                    }
                } else {
                    int r = len%k;
                    ans += y*r + x*(len-r)/k;
                }
            } else {
                if((l1>=0 && a[l1]>mx) || (i<n && a[i]>mx)) {
                    ans += y*len;
                } else {
                    if(len>=1 && len<k) {
                        cout <<"-1\n";
                        return;
                    } else {
                        if(len) {
                            ans += x + y*(len-k);
                        }
                    }
                }
            }
            j++;
            l1 = i;
            // cout <<ans <<endl;
        }
    }
    if(l1<n-1) {
        int i = n;
        int len = i-l1-1;
        int mx = 0;
        rep(i2,l1+1,i) {
            max_self(mx, a[i2]);
        }
        if(x <= k*y) {
            if(len>=1 && len<k) {
                if((l1>=0 && a[l1]>mx) || (i<n && a[i]>mx)) {
                    ans += y*len;
                } else {
                    cout <<"-1\n";
                    return;
                }
            } else {
                int r = len%k;
                ans += y*r + x*(len-r)/k;
            }
        } else {
            if((l1>=0 && a[l1]>mx) || (i<n && a[i]>mx)) {
                ans += y*len;
            } else {
                if(len>=1 && len<k) {
                    cout <<"-1\n";
                    return;
                } else {
                    if(len) {
                        ans += x + y*(len-k);
                    }
                }
            }
        }        
    }
    if(j==m) {
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}