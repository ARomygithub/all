#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q;
ll x[mxn];

struct node {
    ll mx1, mx2;
} st[1<<19];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].mx1 = x;
        st[i].mx2 = 0;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    ll a[4];
    a[0] = st[2*i].mx1; a[1] = st[2*i].mx2; a[2]=st[2*i+1].mx1; a[3]=st[2*i+1].mx2;
    sort(a,a+4);
    st[i].mx1 = a[3];
    st[i].mx2 = a[2];
    return;
}

pair<ll,ll> qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return make_pair(st[i].mx1, st[i].mx2);
    }
    int m2=(l2+r2)/2;
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    ll a[4];
    if(l1<=m2) {
        pair<ll,ll> p1 = qry(l1,r1,2*i,l2,m2);
        a[0] = p1.first; a[1] = p1.second;
    } else {
        a[0] = 0; a[1] = 0;
    }
    if(r1>m2) {
        pair<ll,ll> p2 = qry(l1,r1,2*i+1,m2+1,r2);
        a[2] = p2.first; a[3] = p2.second;
    } else {
        a[2] = 0; a[3] = 0;
    }
    sort(a,a+4);
    return make_pair(a[3],a[2]);
}

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>x[i]; upd(i,x[i]);
    }
    cin >>q;
    while(q--) {
        char qt; cin >>qt;
        if(qt=='U') {
            int i, r; cin >>i >>r; i--;
            upd(i,r);
        } else {
            int l,r; cin >>l >>r; l--, r--;
            pair<ll,ll> p = qry(l,r);
            cout <<p.first+p.second <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}