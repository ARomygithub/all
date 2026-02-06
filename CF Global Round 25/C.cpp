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
int n,m,k,t;
int a[mxn];

void solve() {
    cin >>n >>m >>k;
    int ka = k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> v;
    ll ans = 0;
    sort(a,a+n);
    rep(i,0,n) {
        int temp = min(m,k);
        if(temp>0) {
            v.push_back(temp);
            ans += 1ll*temp*a[i];
            k -=temp;
        } else {
            break;
        }
    }
    ll temp = 1ll*ka*ka;
    rep(i,0,sz(v)) {
        temp -= 1ll*v[i]*v[i];
    }
    temp /=2;
    // cout <<ans <<" " <<temp <<endl;
    cout <<ans+temp <<"\n";
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