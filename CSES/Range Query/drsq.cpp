#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q;
ll x[mxn];

struct node {
    ll mn, s;
} st[1<<19];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].mn=x;
        st[i].s=x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].s;
    }
    int m2=(l2+r2)/2;
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
        int qt, a,b; cin >>qt >>a >> b; a--, b--;
        if(qt==2)
            cout <<qry(a,b) <<"\n";
        else {
            upd(a,b+1);
        }
    }
}