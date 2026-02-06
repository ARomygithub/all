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
const ll mod=998244353;
int n,t;
string s;

void solve() {
    cin >>s;
    n = s.length();
    int fact=0;
    ll ans2=1,ans1=0;
    for(int i=0;i<n;) {
        int j=i;
        while(j<n &&s[i]==s[j]) {
            j++;
        }
        ans2 = (ans2*(j-i))%mod;
        ans1 += j-i-1;
        fact +=j-i-1;
        i = j;
    }
    for(int i=1;i<=fact;i++) {
        ans2 = ans2*i%mod;
    }
    cout <<ans1 <<" " <<ans2 <<"\n";
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