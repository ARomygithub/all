#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,q;
ll b[mxn], a[mxn];

struct node {
    int mx, pref,suf;
} st[1<<18];

void upd(int l1, ll x, int i=1, int l2=0, int r2=n-2) {
    if(l2==r2) {
        st[i].mx=(x!=0);
        st[i].pref=(x!=0);
        st[i].suf=(x!=0);
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    st[i].mx = max(st[2*i].mx,st[2*i+1].mx);
    st[i].pref = st[2*i].pref;
    st[i].suf = st[2*i+1].suf;
    if(!((b[m2]<=0 &&b[m2+1]<=0) || (b[m2]>=0 && b[m2+1]>=0))) {
        max_self(st[i].mx, st[2*i].suf+st[2*i+1].pref);
        if(st[2*i].pref==m2-l2+1) {
            max_self(st[i].pref, st[2*i].suf+st[2*i+1].pref);
        }
        if(st[2*i+1].suf==r2-m2) {
            max_self(st[i].suf, st[2*i].suf+st[2*i+1].pref);
        }
    }
}

int qry2(int l1, int r1, int i=1, int l2=0, int r2=n-2) {
    if(l2==l1) {
        return min(st[i].pref,r1-l1+1);
    }
    int m2=(l2+r2)/2;
    if(l1<=m2) {
        int ret = qry2(l1,min(m2,r1),2*i,l2,m2);
        if(ret==m2-l2+1 && r1>m2 && !((b[m2]<=0 &&b[m2+1]<=0) || (b[m2]>=0 && b[m2+1]>=0))) {
            ret += qry2(m2+1,r1,2*i+1,m2+1,r2);
        }
        return ret;
    } else {
        return qry2(l1,r1,2*i+1,m2+1,r2);
    }
}

int qry3(int l1, int r1, int i=1, int l2=0, int r2=n-2) {
    if(r1==r2) {
        return min(st[i].suf,r1-l1+1);
    }
    int m2=(l2+r2)/2;
    if(r2>m2) {
        int ret = qry3(max(l1,m2+1),r1,2*i+1,m2+1,r2);
        if(ret==r2-m2 && l1<=m2 && !((b[m2]<=0 &&b[m2+1]<=0) || (b[m2]>=0 && b[m2+1]>=0))) {
            ret += qry3(l1,m2,2*i,l2,m2);
        }
        return ret;
    } else {
        return qry3(l1,r1,2*i,l2,m2);
    }
}

int qry(int l1, int r1, int i=1, int l2=0, int r2=n-2) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mx;
    }
    int m2=(l2+r2)/2;
    int le = l1<=m2?qry(l1,r1,2*i,l2,m2):0;
    int ri = r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0;
    int ret=max(le,ri);
    if(l1<=m2 && r1>m2) {
        max_self(ret, qry3(l1,m2)+qry2(m2+1,r1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=1;i<n;i++) {
        b[i-1] = a[i]-a[i-1];
        upd(i-1,b[i-1]);
    }
    cin >>q;
    while(q--) {
        int qt; cin >>qt;
        if(qt==2) {
            int l,r; cin >>l >>r; l--,r--;
            cout <<max((l<=r-1?qry(l,r-1)+1:1),1) <<"\n";
        } else {
            int l,r,u; cin >>l >>r >>u; l--,r--;
            b[l-1] +=u;
            if(r<=n-2) b[r] -=u;
            upd(l-1,b[l-1]);
            upd(r,b[r]);
        }
    }
}
