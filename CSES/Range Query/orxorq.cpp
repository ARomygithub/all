#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=1<<17;
int n, m, k;
ll a[mxn];

struct node {
    ll ox;
    bool op;
} st[1<<18];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].ox = x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    if(st[i].op) {
        st[i].ox = st[2*i].ox | st[2*i+1].ox;
    } else {
        st[i].ox = st[2*i].ox ^ st[2*i+1].ox;
    }
}

void solve() {
    cin >>k >>m;
    n = 1<<k;
    for(int i=1, l=1;i<2*n;l++) {
        while(i<1<<l) {
            if((k-l)%2==1) {
                st[i].op=false;
            } else {
                st[i].op = true;
            }
            i++;
        }
    }
    for(int i=0;i<n;i++) {
        int r; cin >>r;
        upd(i,r);
    }
    while(m--) {
        int p,b; cin >>p >>b; p--;
        upd(p,b);
        cout <<st[1].ox <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
