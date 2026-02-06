#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define sz(x) (int)(x).size()

typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;

template<typename T>
void min_self(T& a, T b) {
    a = min(a,b);
}

const int mxn=1e6;
int n;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    vector<pll> vr(n);
    ll b=0,q=0;
    for(int i=n-2;i>=1;i--) {
        b +=a[i]; q++;
        vr[i] = {b,q};
        if(i<n-2) {
            if(vr[i+1].fi*vr[i].se<vr[i].fi*vr[i+1].se || (vr[i+1].fi*vr[i].se==vr[i].fi*vr[i+1].se && vr[i+1].fi<vr[i].fi)) {
                vr[i].fi = vr[i+1].fi;
                vr[i].se = vr[i+1].se;
            }
        }
    }
    ll sum0n = a[0]+a[n-1];
    double ans=1.0*sum0n/2;
    if(n>3) {
        min_self(ans,1.0*(sum0n+vr[2].fi)/(2+vr[2].se));
    }
    ll sum=sum0n,ct=2;
    for(int i=1;i<n-2;i++) {
        sum +=a[i], ct++;
        min_self(ans, 1.0*sum/ct);
        if(i+2<n-1) {
            min_self(ans,1.0*(sum+vr[i+2].fi)/(ct+vr[i+2].se));
        }
    }
    // sum = sum0n,ct=2;
    // min_self(ans, 1.0*sum/ct);
    // for(int i=n-2;i>1;i--) {
    //     sum +=a[i], ct++;
    //     min_self(ans, 1.0*sum/ct);
    // }
    cout <<fixed <<setprecision(2) <<ans <<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}