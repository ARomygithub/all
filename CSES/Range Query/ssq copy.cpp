#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 50000, mod=1e9+7;
int n, q;
ll x[mxn];

struct node {
    ll s, mxl, mxr, mx;
} st[1<<15];
/*
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
*/
void upd(int l1, int x1, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].s=x1;
        st[i].mxl=st[i].mxr=x1;
        st[i].mx =x1;
        // st[i].mxe = x1;
        return;
    }
    int m2 = (l2+r2)/2;
    // psh(i,l2,m2,r2);
    if(l1<=m2) {
        upd(l1,x1,2*i,l2,m2);
    } else {
        upd(l1,x1,2*i+1,m2+1,r2);
    }
    st[i].s = st[2*i].s + st[2*i+1].s;
    st[i].mxl = max(st[2*i].mxl,st[2*i].s+st[2*i+1].mxl);
    st[i].mxr = max(st[2*i+1].mxr,st[2*i].mxr+st[2*i+1].s);
    st[i].mx = max({st[2*i].mx,st[2*i+1].mx,st[2*i].mxr+st[2*i+1].mxl});
    // st[i].mxe = max(st[2*i].mxe, st[2*i+1].mxe);
}
/*
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
*/
ll qry4(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].s;
    }
    int m2=(l2+r2)/2;
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    return (l1<=m2?qry4(l1,r1,2*i,l2,m2):0)+(r1>m2?qry4(l1,r1,2*i+1,m2+1,r2):0);
}

ll qry2(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mxl;
    }
    int m2=(l2+r2)/2;
    if(l1<=m2 && r1>m2) {
        return max(qry2(l1,m2,2*i,l2,m2), qry4(l1,m2,2*i,l2,m2)+qry2(m2+1,r1,2*i+1,m2+1,r2));
    } else if(l1<=m2) {
        return qry2(l1,r1,2*i,l2,m2);
    } else if(r1>m2) {
        return qry2(l1,r1,2*i+1,m2+1,r2);
    } else {
        return 0;
    }
}
 
ll qry3(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mxr;
    }
    int m2=(l2+r2)/2;
    if(l1<=m2 && r1>m2) {
        max(qry3(m2+1,r1,2*i+1,m2+1,r2), qry4(m2+1,r1,2*i+1,m2+1,r2)+qry3(l1,m2,2*i,l2,m2));
    } else if(l1<=m2) {
        return qry3(l1,r1,2*i,l2,m2);
    } else if(r1>m2) {
        return qry3(l1,r1,2*i+1,m2+1,r2);
    } else {
        return 0;
    }
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mx;
    }
    int m2=(l2+r2)/2;
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    return max(max((l1<=m2?qry(l1,min(r1,m2),2*i,l2,m2):-1e5),(r1>m2?qry(max(l1,m2+1),r1,2*i+1,m2+1,r2):-1e5)), (l1<=m2&&r1>m2?qry3(l1,min(r1,m2),2*i,l2,m2)+qry2(max(l1,m2+1),r1,2*i+1,m2+1,r2):-1e5));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>x[i]; upd(i,x[i]);
    }
    cin >>q;
    while(q--) {
        int l,r; cin >>l >>r; l--, r--;
        cout <<qry(l,r) <<"\n";
    }
}