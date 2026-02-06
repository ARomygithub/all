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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    vector<int> v;
    rep(i,0,n) {
        cin >>a[i];
        if(a[i]>0) {
            v.push_back(i);
        }
    }
    if(sz(v)==1) {
        cout <<"-1\n";
        return;
    }
    int ct = sz(v);
    ll ans = 1e18;
    vector<ll> pref(ct,0);
    rep(i,0,ct) {
        pref[i] = 1ll*v[i] + (i>0?pref[i-1]:0ll);
    }
    for(int i=2;i<=ct;i++) {
        if((ct%i)==0) {
            ll temp = 0;
            for(int j=0;j<ct;j+=i) {
                int l=j,r=j+i-1;
                int mid = (l+r)/2;
                ll temp2 = 1ll*v[mid]*(mid-l+1);
                temp2 -= 1ll*v[mid]*(r-mid);
                temp2 -= pref[mid] - (l-1>=0?pref[l-1]:0ll);
                temp2 += pref[r] - pref[mid];
                temp +=temp2;
            }
            min_self(ans, temp);
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