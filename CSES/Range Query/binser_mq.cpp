#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q;
ll x[mxn];

struct node {
    ll mn,mx, s, lz;
} st[1<<19];

void app(int i, ll x, int l2, int r2) {
    st[i].mn +=x;
    st[i].mx +=x;
    st[i].s +=x*(r2-l2+1);
    st[i].lz +=x;
}

void psh(int i, int l2, int m2, int r2) {
    app(2*i, st[i].lz, l2, m2);
    app(2*i+1, st[i].lz, m2+1, r2);
    st[i].lz=0;
}

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].mn=x;
        st[i].s=x;
        st[i].mx=x;
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i,l2,m2,r2);
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
    st[i].mx = max(st[2*i].mx,st[2*i+1].mx);
}

void upd2(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        app(i,x,l2,r2);
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i,l2,m2,r2);
    if(l1<=m2) {
        upd2(l1,r1,x,2*i,l2,m2);
    }
    if(r1>m2) {
        upd2(l1,r1,x,2*i+1,m2+1,r2);
    }
    st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
    st[i].mx = max(st[2*i].mx,st[2*i+1].mx);
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mx;
    }
    int m2=(l2+r2)/2;
    psh(i,l2,m2,r2);
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    return max((l1<=m2?qry(l1,r1,2*i,l2,m2):0),(r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0));
}

int qry2(ll x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        return l2;
    }
    int m2 = (l2+r2)/2;
    psh(i,l2,m2,r2);
    if(st[2*i].mx>=x) return qry2(x,2*i,l2,m2);
    return qry2(x,2*i+1,m2+1,r2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>x[i]; upd(i,x[i]);
    }
    while(q--) {
        ll r; cin >>r;
        int lb =qry(0,n-1)>=r?qry2(r):n;
        if(lb>=n) {
            cout <<"0 ";
        } else {
            cout <<lb+1 <<" ";
            upd2(lb,lb,-r);
        }
    }
}