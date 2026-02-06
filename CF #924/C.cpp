#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
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
int n,x,t;

void solve() {
    cin >>n >>x;
    int ans = 0;
    int n1 = n+x-2;
    set<int> s;
    for(int i=1;1ll*i*i<=n1;i++) {
        if((n1%i)==0) {
            int j = n1/i;
            if((i%2)==0 && i>=x*2) {
                s.insert((i+2)/2);
                ans++;
            }
            if((j%2)==0 && j!=i && j>=x*2) {
                ans++;
                s.insert((j+2)/2);
            }
        }
    }
    int n2 = n-x;
    for(int i=1;1ll*i*i<=n2;i++) {
        if((n2%i)==0) {
            int j = n2/i;
            if((i%2)==0 && i>=x*2-2) {
                s.insert((i+2)/2);
                ans++;
            }
            if((j%2)==0 && j!=i && j>=x*2-2) {
                s.insert((j+2)/2);
                ans++;
            }
        }
    }
    // cout <<ans <<"\n";
    cout <<sz(s) <<"\n";
    // for(int v : s) {
    //     cout <<v <<" " <<flush;
    //     assert(x == v-abs(((n-1)%(v*2-2))-(v-1)));
    // }
    // cout <<"\n";
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