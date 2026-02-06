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

const int mxn=3e5;
int n;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll s = 0;
    rep(i,0,n) {
        s += a[i];
    }
    s *=1ll*(n-1);
    // s /=2;
    ll ct = 0;
    ll bts = 1e8;
    sort(a,a+n);
    int l = 0;
    per(i,n-1,-1) {
        while(a[l]+a[i]<bts) {
            // cout <<l <<endl;
            l++;
            if(l>=i) break;
        }
        if(l<i) {
            ct += i-l;
        } else {
            break;
        }
    }
    // cout <<ct <<endl;
    s -= ct*bts;
    cout <<s <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}