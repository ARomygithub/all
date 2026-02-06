#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int a,b,c,d;
ll f,t;

void solve() {
    cin >>a >>b >>c >>d >>f;
    ll l=0,r=1e15;
    ll ans=-1;
    while(l<=r) {
        ll mid = (l+r)/2;
        bool flag=true;
        ll ff=0;
        if(mid>1e5 && a>0) {
            flag = false;
        }
        ff +=mid*mid*mid*a;
        if(mid>1e8 && b>0) {
            flag = false;
        }
        ff +=mid*mid*b;
        ff +=mid*c;
        ff = ff+d;
        if(flag && ff==f) {
            ans = mid;
            break;
        } else if(flag && ff<f) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout <<ans <<"\n";
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