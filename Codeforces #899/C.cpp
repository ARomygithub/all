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
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    int firstPos = -1;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        if(firstPos==-1 && a[i]>0) {
            firstPos = i;
        }
    }
    if(n==1) {
        cout <<max(a[0],0) <<"\n";
        return;
    }
    ll ans=0;
    if((firstPos%2)==0 || firstPos>=3) {
        for(int i=0;i<n;i++) {
            ans +=max(a[i],0);
        }
    } else {
        ans +=max(a[1]+a[0],0);
        for(int i=2;i<n;i++) {
            ans += max(a[i],0);
        }
    }
    cout <<ans <<"\n";
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