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
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    rep(i,0,n-3) {
        if(a[i+1]==a[i+2]) {
            if(a[i]+a[i+1]+a[i+2]>a[i+3]) {
                cout <<a[i] <<" " <<a[i+1] <<" " <<a[i+2] <<" " <<a[i+3] <<"\n";
                return;
            }
        }
    }
    int x = -1;
    rep(i,0,n-1) {
        if(x!=-1) {
            if(a[i]+x*2 > a[i+1]) {
                cout <<a[i] <<" " <<x <<" " <<x <<" " <<a[i+1] <<"\n";
                return;
            }
        }
        if(i>0 && a[i]==a[i-1]) {
            x = a[i];
        }
    }
    x = -1;
    per(i,n-1,0) {
        if(x!=-1) {
            if(a[i-1]+x*2 > a[i]) {
                cout <<a[i-1] <<" " <<x <<" " <<x <<" " <<a[i] <<"\n";
                return;
            }
        } else {
            if(i+1<n && a[i]==a[i+1]) {
                x = a[i];
            }
        }
    }
    cout <<"-1\n";
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