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
int r,c,t;

void solve() {
    cin >>r >>c;
    ll ans=0;
    for(int i=0;i<=r;i++) {
        for(int i2=i+2;i2<=r;i2+=2) {
            for(int j=0;j<=c;j++) {
                for(int j2=j+2;j2<=c;j2+=2) {
                    if((i2-i)<=(j2-j) && (i2-i)*2>=(j2-j)) {
                        ans++;
                    }
                }
            }
        }
    }
    cout <<ans <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}