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

const int mxn=1e5;
int n,t;
string x,y;

void solve() {
    cin >>x >>y;
    n = x.length();
    int idx = 0;
    while(idx < n && x[idx]==y[idx]) {
        idx++;
    }
    if(idx<n) {
        if(x[idx]<y[idx]) {
            swap(x[idx],y[idx]);
        }
        rep(i,idx+1,n) {
            if(x[i]>y[i]) {
                swap(x[i],y[i]);
            }
        }
    }
    cout <<x <<"\n";
    cout <<y <<"\n";
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