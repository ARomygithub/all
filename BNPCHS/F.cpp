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

const int mxn=5e4;
const ll mod=1e9+7;
int n;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    vector<ll> ct(512,0);
    ct[0] = 1;
    for(int i=0;i<n;i++) {
        vector<ll> ct_diff(512,0);
        for(int j=0;j<512;j++) {
            ct_diff[a[i]^j] =(ct_diff[a[i]^j]+ct[j])%mod;
        }
        for(int j=0;j<512;j++) {
            ct[j] = (ct[j]+ct_diff[j])%mod;
        }
    }
    cout <<(ct[0]+mod-1)%mod <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}