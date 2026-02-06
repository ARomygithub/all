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
int n,m,k,a,b;

void solve() {
    cin >>n >>m >>k >>a >>b;
    int ans=0;
    int l=0,r=n;
    while(l<=r) {
        int mid=(l+r)/2;
        mid -=(mid%3);
        if(mid<l) {
            mid +=3;
            if(mid>r) {
                break;
            }
        }
        ll harga =1ll*m*mid;
        int najimi = mid/3;
        int osana = mid-najimi;
        bool flag=n>=harga;
        flag &=a>=osana*k;
        flag &=b>=najimi*k;
        if(flag) {
            ans = mid;
            l = mid+1;
        }  else {
            r = mid-1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}