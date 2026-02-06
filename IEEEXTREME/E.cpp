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
int n,x;
int a[mxn];

void solve() {
    cin >>n >>x;
    ll sum=0;
    int ans=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        sum +=a[i];
    }
    sort(a,a+n);
    if(sum>=x) {
        cout <<ans <<"\n";
        return;
    }
    int lv=0,rv=-1;
    for(int l=0,r=n-1;l<=r;) {
        ans++;
        sum +=1ll*(a[r]-lv)*(a[r]-lv);
        sum -=a[r];
        rv = a[r];
        r--;
        if(sum>=x) {
            cout <<ans <<"\n";
            return;
        }
        if(l>r) break;
        ans++;
        sum +=1ll*(rv-a[l])*(rv-a[l]);
        sum -=a[l];
        lv = a[l];
        l++;
        if(sum>=x) {
            cout <<ans <<"\n";
            return;
        }
    }
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}