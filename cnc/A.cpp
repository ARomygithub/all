#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mxl=1e18;
ll a,b,c,d,f,t;

void solve() {
    cin >>a >>b >>c >>d >>f;
    // d -=f;
    ll l=1,r=f;
    ll ans=-1;
    if(f==d) {
        cout <<"0\n";
        return;
    }
    while(l<=r) {
        ll mid=(l+r)/2;
        bool lebih=0;
        ll temp = a;
        if(temp>f || (((mxl-b)/mid))<=temp) {
            lebih=1;
        }
        temp = temp*mid+b;
        if(temp>f || (((mxl-c)/mid))<=temp) {
            lebih=1;
        }
        temp = temp*mid+c;
        if(temp>f || (((mxl-d)/mid))<=temp) {
            lebih=1;
        }
        temp = temp*mid+d;
        if(temp>f) {
            lebih=1;
        }
        if(lebih) {
            r = mid-1;
        } else {
            if(temp==f) {
                cout <<mid <<"\n";
                return;
            } else if(temp<f) {
                l = mid+1;
            }
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