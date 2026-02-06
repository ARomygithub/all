#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

int n;

void solve() {
    cin >>n;
    for(int i=2;1ll*i*i<=n;i++) {
        if((n%i)==0) {
            int d = n /i;
            int a = d, b = n-a;
            cout <<a <<" " <<b <<"\n";
            return;
        }
    }
    int a = 1, b = n-1;
    cout <<a <<" " <<b <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}