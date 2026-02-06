#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,k;
ll a[mxn], d[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // a[n-1]-d[n-1] selalu opsi
    // 2 udah. s- min(0,n-2)
    // 2 biar gapapa jg bisa. genap udah.
    // boleh ga eksitasi ga.
    cin >>n >>k;
    for(int i=0;i<n;i++) cin >>a[i];
    for(int i=0;i<n;i++) cin >>d[i];
    if(k>=2) {
        ll ans=a[n-1]-d[n-1];
        ll s=0;
        for(int i=0;i<n;i++) {
            s +=a[i];
        }
        sort(d,d+n-1);
        ans =max(ans,s-d[0]);
        cout <<ans;
    } else {
        ll ans=0;
        ll temp=0; ll s1=0;
        for(int i=0;i<n-1;i++) {
            s1 +=a[i];
        }
        ll d0=d[0], df=d[n-1];
        sort(d,d+n-1);
        temp=max(s1-d[0],a[n-1]-df);
        ans = max(ans,temp);
        ll s = s1+a[n-1];
        sort(d,d+n);
        ans = max(ans,s-d[0]-d[1]);
        sort(a+1,a+n);
        ll temp1=a[0];
        for(int i=2;i<n;i++) {
            temp1 +=a[i];
        }
        temp1 -=d0;
        ans = max(ans,temp1);
        cout <<ans;
    }
}
