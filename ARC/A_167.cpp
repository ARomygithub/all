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
int a[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    sort(a,a+n);
    vector<int> v(m,0);
    for(int i=n-1;i>=0;i--) {
        if(i+m-n>=0) {
            v[i+m-n] +=a[i];
        } else {
            int temp = (i+m-n)*(-1);
            temp--;
            v[temp] +=a[i];
        }
    }
    ll ans=0;
    for(int i=0;i<m;i++) {
        ans +=1ll*v[i]*v[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}