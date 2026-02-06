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

const int mxn=50;
int n,m,k,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>m >>k;
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        sum +=a[i];
    }
    for(int i=0;i<m;i++) {
        cin >>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    if(k%2) {
        if(b[m-1]>a[0]) {
            sum +=b[m-1];
            sum -=a[0];
        }
    } else {
        if(b[m-1]>a[0]) {
            sum -= a[0];
            sum +=b[m-1];
            sum -=max(b[m-1],a[n-1]);
            sum +=min(a[0],b[0]);
        } else {
            sum -=a[n-1];
            sum +=b[0];
        }
    }
    cout <<sum <<"\n";
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