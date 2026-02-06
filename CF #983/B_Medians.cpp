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

const int mxn=2e5;
int n,k,t;

void solve() {
    cin >>n >>k;
    if(n%2) {
        if(n==1) {
            cout <<"1\n1\n";
            return;
        }
        int m = 3;
        int p2,p3;
        if(k%2) {
            p2 = k-1;
            p3 = k+2;
            if(p2==0 || p3>n) {
                cout <<"-1\n";
                return;
            }
        } else {
            p2 = k;
            p3 = k+1;
        }
        cout <<m <<"\n";
        cout <<"1 " <<p2 <<" " <<p3 <<"\n";

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