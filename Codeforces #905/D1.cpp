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
int n,m,t;
int a[mxn], b[mxn];

void solve() {
    cin >>n >>m;
    // a[0] = 1;
    rep(i,0,n-1) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    sort(a,a+n-1);
    sort(b,b+n);
    int idx=0;
    vector<int> v;
    rep(i,0,n) {
        if(a[idx]<b[i]) {
            v.push_back(i);
            idx++;
            if(idx>=n-1) break;
        }
    }
    int last=n-1;
    int idxa=-1;
    per(i,sz(v)-1,-1) {
        if(v[i]==last) {
            idxa = i;
            last--;
        } else {
            break;
        }
    }
    int atas = -1;
    if(idxa==-1) {
        atas = b[n-1]-1;
    } else {
        atas = a[idxa]-1;
        if(v[idxa]>0) {
            min_self(atas,b[v[idxa]-1]-1);
        }
    }
    ll ans=0;
    ll temp= min(m,atas);
    // cout <<idxa <<" " <<atas <<" " <<idx <<"\n";
    ans +=temp*(1ll*n-idx-1);
    ans +=(1ll*m-temp)*(1ll*n-idx);
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