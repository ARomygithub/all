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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;

void solve() {
    cin >>n;
    if(n==1) {
        cout <<"1\n1\n";
    } else if(n==2) {
        cout <<"2\n1 2\n";
    } else if(n==3) {
        cout <<"2\n1 2 2\n";
    } else if(n==4) {
        cout <<"3\n1 2 2 3\n";
    } else if(n==5) {
        cout <<"3\n1 2 2 3 3\n";
    } else {
        cout <<"4\n";
        rep(i,1,n+1) {
            cout <<(i%4)+1 <<" \n"[i==n];
        }
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