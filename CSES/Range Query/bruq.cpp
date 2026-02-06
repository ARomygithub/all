#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q;
ll x[mxn];

struct node {
    ll s, ct[31];
    bool lz[31]={};
} st[1<<19];

void app(int i, int bp, int l2, int r2) {
    st[i].s +=(ll)(1<<bp)*(st[i].ct[bp]*(-2)+r2-l2+1);
    st[i].ct[bp] = r2-l2+1-st[i].ct[bp];
    st[i].lz[bp] ^=1;
}

void psh(int i, int l2, int m2, int r2) {
    for(int j=0;j<31;j++) {
        if(st[i].lz[j]) {
            app(2*i,j,l2,m2);
            app(2*i+1,j,m2+1,r2);
            st[i].lz[j]=false;
        }
    }
}

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].s=x;
        for(int j=0;j<31;j++) {
            st[i].ct[j]= (x>>j)&1;
        }
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i,l2,m2,r2);
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    st[i].s = st[2*i].s + st[2*i+1].s;
    for(int j=0;j<31;j++) {
        st[i].ct[j] = st[2*i].ct[j]+st[2*i+1].ct[j];
    }
}

void upd2(int l1, int r1, int x, int i=1, int l2=0, int r2=n-1) {
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
    st[i].s = st[2*i].s + st[2*i+1].s;
    for(int j=0;j<31;j++) {
        st[i].ct[j] = st[2*i].ct[j]+st[2*i+1].ct[j];
    }
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].s;
    }
    int m2=(l2+r2)/2;
    psh(i,l2,m2,r2);
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    return (l1<=m2?qry(l1,r1,2*i,l2,m2):0) + (r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0);
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
        int qt; cin >>qt;
        if(qt==1) {
            int l,r, b; cin >>l >>r >>b; l--, r--;
            upd2(l,r,b);
        } else {
            int l,r; cin >>l >>r; l--, r--;
            cout <<qry(l,r) <<"\n";
        }
    }
}