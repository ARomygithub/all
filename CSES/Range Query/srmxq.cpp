#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q;
ll x[mxn];

struct node {
    ll mx;
} st[1<<19];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].mx=x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    st[i].mx = max(st[2*i].mx,st[2*i+1].mx);
}

int qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mx;
    }
    int m2=(l2+r2)/2;
    return max(l1<=m2?qry(l1,r1,2*i,l2,m2):0, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0);
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
        int a,b; cin >>a >> b; a--, b--;
        if(x[a]==x[b] && x[a]==qry(a,b)) {
            cout <<"YA\n"; 
        } else {
            cout <<"TIDAK\n";
        }
    }
}