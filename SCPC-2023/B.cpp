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
int n,d;
int p[mxn];

void solve() {
    cin >>n >>d;
    for(int i=0;i<n;i++) {
        cin >>p[i];
    }
    sort(p, p+n);
    int l=0;
    int ans=0;
    for(int r=n-1;r>=l;r--) {
        int ct = (d+1+p[r]-1)/p[r];
        if(ct<=r-l+1) {
            l += ct-1;
            ans++;
        } else {
            break;
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