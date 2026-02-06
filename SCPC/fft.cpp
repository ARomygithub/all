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
int n;

const ll mod= 998244353;
const ll root = 15311432;
const ll root_1 = 469870224;
const ll root_pw = 1<<23;

void fft(vector<ll>& a, bool inv) {
    ll n = sz(a);
    for(int i=1,j=0;i<n;i++) {
        ll bit = n>>1;
        for(;j&bit; bit>>=1) {
            j ^=bit;
        }
        j ^=bit;
        if(i<j) {
            swap(a[i],a[j]);
        }
    }
    for(int len=2;len<=n;len<<=1) {
        ll wlen = inv? root_1: root;
        for(int i=len;i<root_pw;i<<=1) {
            wlen = 1ll*wlen*wlen%mod;
        }
        for(int i=0;i<n;i+=len) {
            ll w = 1;
            for(int j=0;j<len/2;j++) {
                ll u = a[i+j], v = 1ll*a[i+j+len/2]*w%mod;
                a[i+j] = u+v<mod?u+v:u+v-mod;
                a[i+j+len/2] = u-v>=0?u-v:u-v+mod;
                w = 1ll*w*wlen%mod;
            }
        }
    }
    if(inv) {
        ll n_1 = inverse(n,mod);
        for(int i=0;i<a.size();i++) {
            a[i] = 1ll*a[i]*n_1%mod;
        }
    }
} 

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    ll n = 1;
    while(n<sz(a)+sz(b)) {
        n <<=1;
    }
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for(int i=0;i<n;i++) {
        fa[i] = (fa[i]*fb[i])%mod;
    }
    fft(fa,true);
    vector<ll> res(n);
    for(int i=0;i<n;i++) {
        res[i] = fa[i];
    }
    return res;
}

void solve() {
    cin >>n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}