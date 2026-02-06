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
int s[mxn],e[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>s[i] >>e[i];
    }
    int w=s[0];
    bool flag=1;
    for(int i=1;i<n&&flag;i++) {
        if(s[i]>=w && e[i]>=e[0]) {
            flag = 0;
        }
    }
    if(flag) {
        cout <<w <<"\n";
    } else {
        cout <<"-1\n";
    }
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