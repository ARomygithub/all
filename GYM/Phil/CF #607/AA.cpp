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

const int mxn=1e7,mxa=1e9;
int n;
int fib[mxn];

void solve() {
    cin >>n;
    fib[0] = 1;
    fib[1] = 2;
    int last=mxn-1;
    rep(i,2,mxn) {
        fib[i] = fib[i-1]+fib[i-2];
        if(fib[i]>mxa) {
            last = i;
            break;
        }
    }
    rep(i,1,last+1) {
        if((n%fib[i])==0) {
            int m = 1ll*(n/fib[i])*fib[i-1];
            cout <<m <<"\n";
            return;
        }
    }
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}