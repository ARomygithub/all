#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
const ll INF = LLONG_MAX;

const int mxn= 2e5, mod=1e9+7;
int n, q, t[mxn], sts=1;
vector<int> v={0};

struct node {
    int lc, rc;
    ll s;
} st[mxn*40];

void upd(int &i, int l1, int x, int l2=0, int r2=n-1) {
    st[sts].lc = st[i].lc;
    st[sts].rc = st[i].rc;
    st[sts].s = st[i].s+x;
    i = sts++; // i reference, i asal berubah juga.
    if(l2==r2) {
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(st[i].lc,l1,x,l2,m2);
    } else {
        upd(st[i].rc,l1,x,m2+1,r2);
    }
}

ll qry(int i, int l1, int r1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].s;
    }
    int m2=(l2+r2)/2;
    // return min(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)1e9, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)1e9);
    return (l1<=m2?qry(st[i].lc,l1,r1,l2,m2):0) + (r1>m2?qry(st[i].rc,l1,r1,m2+1,r2):0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>t[i]; upd(v[0],i,t[i]);
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int k,a,x; cin >>k >>a >>x; k--, a--;
            upd(v[k],a,x-qry(v[k],a,a));
        } else if(qt==2) {
            int k,a,b; cin >>k >>a >>b; k--, a--, b--;
            cout <<qry(v[k],a,b) <<"\n";
        } else if(qt==3) {
            int k; cin >>k; k--;
            v.push_back(v[k]);
        }
    }
}