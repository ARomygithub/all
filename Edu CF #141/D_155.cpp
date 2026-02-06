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

const int mxn=3e5;
const ll mod=998244353;
int n;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        if(i>0) {
            a[i] ^=a[i-1];
        }
    }
    ll ans=0;
    for(int i=0;i<30;i++) {
        vector<ll> ct(2,0);
        vector<ll> sum(2,0);
        ct[0]++;
        ll temp=0;
        for(int j=0;j<n;j++) {
            sum[0] = (sum[0]+ct[0])%mod;
            sum[1] = (sum[1]+ct[1])%mod;
            if(a[j] & (1<<i)) {
                temp = (temp+sum[0])%mod;
                ct[1]++;
            } else {
                temp = (temp+sum[1])%mod;
                ct[0]++;
            }
        }
        temp = (temp*(1ll<<i))%mod;
        ans = (ans+temp)%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}