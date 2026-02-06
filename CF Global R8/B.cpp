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
ll k;

void solve() {
    cin >>k;
    int l=10,r=1000;
    vector<ll> ans;
    while(l<=r) {
        int mid=(l+r)/2;
        vector<ll> v(10);
        rep(i,0,(mid)%10) {
            v[i] = (mid/10)+1;
        }
        rep(i,(mid)%10,10) {
            v[i] = mid/10;
        }
        ll mul=1;
        rep(i,0,10) {
            mul *=v[i];
        }
        if(mul>=k) {
            ans.swap(v);
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    string res="";
    string cf = "codeforces";
    rep(i,0,10) {
        rep(j,0,ans[i]) {
            res +=cf[i];
        }
    }
    cout <<res <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}