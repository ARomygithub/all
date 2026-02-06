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
int n,m,k,p,y,z;
int a[mxn],b[mxn],c[mxn];

void solve() {
    cin >>n >>m >>k >>p >>y >>z;
    ll ans=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        ans +=a[i];
    }
    for(int i=0;i<m;i++) {
        cin >>b[i];
    }
    for(int i=0;i<k;i++) {
        cin >>c[i];
    }
    sort(b,b+m,greater<int>());
    vector<ll> pref(m+1,0);
    int idx=0;
    for(int i=0;i<m;i++) {
        pref[i+1] = pref[i]+b[i];
        if(b[i]>=y) idx=i+1;
    }
    auto ansb = [&](int mi) -> ll {
        min_self(mi,m);
        if(mi>idx) {
            return pref[mi];
        } else {
            return pref[idx]-1ll*(idx-mi)*y;
        }
    };
    sort(c,c+k,greater<int>());
    vector<ll> pref2(k+1,0);
    for(int i=0;i<k;i++) {
        pref2[i+1] = pref2[i]+c[i];
    }
    ll ansc=0;
    ll temp=0;
    for(int i=k;i>=0;i--) {
        if(i<k) {
            temp = (temp+c[i])/z;
        }
        if(i>p) continue;
        max_self(ansc, temp+pref2[i]+ansb(p-i)+ans);
    }
    cout <<ansc <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}