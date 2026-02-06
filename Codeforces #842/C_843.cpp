#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
ll n,x,t;

void solve() {
    cin >>n >>x;
    if((n|x)==n) {
        if(n==x) {
            cout <<n <<"\n";
            return;
        }
        ll temp=0;
        for(int i=0;i<63;i++) {
            if((n&(1ll<<i)) && (!(x&(1ll<<i)))) {
                temp = 1ll<<i;
            }
        }
        if(x==0) {
            ll m= temp*2;
            cout <<m <<"\n";
            return;
        }
        ll b1 = 1ll<<(__builtin_ctzll(x));
        ll c1 = __builtin_ctzll(x);
        if(temp*2>=b1) {
            cout <<"-1\n";
            return;
        } else {
            ll m = x+temp*2;
            cout <<m <<"\n";
            return;
        }
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