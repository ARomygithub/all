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

const int mxn=20;
int n;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    ll ans=0;
    for(int i=1;i<(1<<n);i++) {
        ll temp = 0;
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {
                temp |=a[j];
            }
        }
        ans +=temp;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}