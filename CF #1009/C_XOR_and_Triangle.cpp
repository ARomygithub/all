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
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int x,t;

void solve() {
    cin >>x;
    bool udh = 0;
    int b0=0,b1=0;
    per(j,29,-1) {
        if(!udh) {
            if((x>>j)&1) {
                udh = 1;
            }
        } else {
            if((x>>j)&1) {
                b1 = (1<<j);
            } else {
                b0 = (1<<j);
            }
        }
    }
    if(b0>0 && b1>0) {
        cout <<b0+b1 <<"\n";
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