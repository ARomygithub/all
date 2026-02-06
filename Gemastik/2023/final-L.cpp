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
int n;
ll a[mxn+1], previ[mxn+1];
ll ans[mxn+1];
vector<int> divisor[mxn+1];
// ketat bet. Bisa 2e7 or 1e7 memory. bisa 2e8, 5e8 time complexity.

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i*2;j<=n;j+=i) {
            divisor[j].push_back(i);
        }
    }
    for(int i=n;i>=1;i--) {
        previ[i]= a[i];
        for(int j=i*2;j<=n;j+=i) {
            ll temp=0;
            for(auto di : divisor[j]) {
                if(di>=i) {
                    temp +=a[di];
                }
            }
            previ[j] = temp;
            ans[i] +=max(0ll,previ[j]-a[j]);
            max_self(a[j],previ[j]);
        }
        ans[i] +=(i+1<=n?ans[i+1]:0ll);
    }
    for(int i=1;i<=n;i++) {
        cout <<ans[i] <<" \n"[i==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}