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
int n,t;
int x[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>x[i];
    }
    double ans=0.0;
    sort(x,x+n);
    if(n==5) {
        max_self(ans,1.0*(x[3]+x[4]-x[0]-x[2])/2);
        max_self(ans,1.0*(x[4]+x[2]-x[0]-x[1])/2);
    } else {
        max_self(ans,1.0*(x[n-1]+x[n-2]-x[0]-x[1])/2);
    }
    cout <<fixed <<setprecision(1) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}