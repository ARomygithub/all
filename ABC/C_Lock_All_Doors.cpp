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
int n,r0,l[mxn],t;

void solve() {
    cin >>n >>r0;
    rep(i,0,n) {
        cin >>l[i];
    }
    int le=-1,ri=-1;
    int ct0 = 0;
    rep(i,0,n) {
        if(l[i]==0) {
            if(le==-1) {
                le = i;
            }
            ri = i;
            ct0++;
        }
    }
    int ans = 0;
    if(le != -1) {
        min_self(le, r0);
        max_self(ri, r0-1);
        ans = 2*(ri-le+1) - ct0;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}