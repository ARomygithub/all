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
int a[mxn], p[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,k) {
        cin >>p[i]; p[i]--;
    }
    int x = a[p[0]];
    int l = 0;
    rep(i,0,p[0]+1) {
        if(i==0) {
            if(a[0]!=x) l++;
        } else {
            if(a[i]!=a[i-1]) l++;
        }
    }
    int r = 0;
    per(i,n-1,p[0]-1) {
        if(i==n-1) {
            r += (a[i]!=x);
        } else {
            r += (a[i]!=a[i+1]);
        }
    }
    cout <<max(l,r) <<"\n";
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