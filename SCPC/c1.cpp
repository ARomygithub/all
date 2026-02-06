#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e3;
int n;
ll a[mxn];

ll ct(ll c, ll d) {
    if(c>d) return 0ll;
    else return d-c+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        if(i%2) {
            a[i]=-1ll*a[i];
        }
    }
    ll ans=0;
    if(n>1) {
        for(int i=0;i<n;i+=2) {
            ll s=a[i], j=i+1;
            ans +=(ll)min(a[i],abs(a[i+1]));
            s +=a[j];
            j++;
            ll mins=s;
            while(s>=0 && j<n) {
                if(a[j]<0) {
                    ll l=max(s-mins,1ll);
                    ll r=min(s,(ll)abs(a[j]));
                    ans += ct(l,r);
                }
                s +=a[j];
                mins = min(s,mins);
                j++;
            }
        }
        cout <<ans;
    } else {
        cout <<"0";
    }
}
