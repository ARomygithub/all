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
 
const int mxn= 1e5, mod=998244353;
int n, q;

struct node {
    ll lzx, lzy, lzz;
    ll s1,s2,s3,s4,s5,s6,s7;
} st[1<<18];

void app(int i, ll x, ll y, ll z, int l2, int r2) {
    ll temp7 = x*st[i].s5%mod;
    temp7 = (temp7 + y*st[i].s6%mod)%mod;
    temp7 = (temp7 + z*st[i].s4%mod)%mod;
    temp7 = (temp7 + x*y%mod*st[i].s3%mod)%mod;
    temp7 = (temp7 + x*z%mod*st[i].s2%mod)%mod;
    temp7 = (temp7 + y*z%mod*st[i].s1%mod)%mod;
    temp7 = (temp7 + x*y%mod*z%mod*(r2-l2+1)%mod)%mod;
    st[i].s7 = (st[i].s7 + temp7)%mod;
    ll temp6 = x*st[i].s3%mod;
    temp6 = (temp6 + z*st[i].s1%mod)%mod;
    temp6 = (temp6 + x*z%mod*(r2-l2+1)%mod)%mod;
    st[i].s6 = (st[i].s6 + temp6)%mod;
    ll temp5 = y*st[i].s3%mod;
    temp5 = (temp5 + z*st[i].s2%mod)%mod;
    temp5 = (temp5 + y*z%mod*(r2-l2+1)%mod)%mod;
    st[i].s5 = (st[i].s5 + temp5)%mod;
    ll temp4 = x*st[i].s2%mod;
    temp4 = (temp4 + y*st[i].s1%mod)%mod;
    temp4 = (temp4 + x*y%mod*(r2-l2+1)%mod)%mod;
    st[i].s4 = (st[i].s4 + temp4)%mod;
    st[i].s3 = (st[i].s3 + z*(r2-l2+1)%mod)%mod;
    st[i].s2 = (st[i].s2 + y*(r2-l2+1)%mod)%mod;
    st[i].s1 = (st[i].s1 + x*(r2-l2+1)%mod)%mod;
    st[i].lzx =(st[i].lzx+x)%mod;
    st[i].lzy =(st[i].lzy+y)%mod;
    st[i].lzz =(st[i].lzz+z)%mod;
}

void psh(int i, int l2, int m2, int r2) {
    app(2*i, st[i].lzx, st[i].lzy, st[i].lzz, l2, m2);
    app(2*i+1, st[i].lzx, st[i].lzy, st[i].lzz, m2+1, r2);
    st[i].lzx=0;
    st[i].lzy=0;
    st[i].lzz=0;
}

void upd2(int l1, int r1, ll x, ll y, ll z, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        app(i,x,y,z,l2,r2);
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i,l2,m2,r2);
    if(l1<=m2) {
        upd2(l1,r1,x,y,z,2*i,l2,m2);
    }
    if(r1>m2) {
        upd2(l1,r1,x,y,z,2*i+1,m2+1,r2);
    }
    st[i].s1 = (st[2*i].s1 + st[2*i+1].s1)%mod;
    st[i].s2 = (st[2*i].s2 + st[2*i+1].s2)%mod;
    st[i].s3 = (st[2*i].s3 + st[2*i+1].s3)%mod;
    st[i].s4 = (st[2*i].s4 + st[2*i+1].s4)%mod;
    st[i].s5 = (st[2*i].s5 + st[2*i+1].s5)%mod;
    st[i].s6 = (st[2*i].s6 + st[2*i+1].s6)%mod;
    st[i].s7 = (st[2*i].s7 + st[2*i+1].s7)%mod;
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].s7;
    }
    int m2=(l2+r2)/2;
    psh(i,l2,m2,r2);
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    return (l1<=m2?qry(l1,r1,2*i,l2,m2):0) + (r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0);
}

void solve() {
    cin >>n >>q;
    while(q--) {
        ll l,r, x,y,z; cin >>l >>r >>x >>y >>z; l--,r--;
        upd2(l,r,x,y,z);
        cout <<qry(0,n-1)%mod <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}