#include "bits/stdc++.h"
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

const int mxn=3e5;
int n;
int a[mxn], ans[2][mxn];

struct node {
    ll mn;
} st1[1<<19],st2[1<<19];

void upd1(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st1[i].mn=x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd1(l1,x,2*i,l2,m2);
    } else {
        upd1(l1,x,2*i+1,m2+1,r2);
    }
    st1[i].mn = max(st1[2*i].mn,st1[2*i+1].mn);
}

int qry1(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st1[i].mn;
    }
    int m2=(l2+r2)/2;
    return max(l1<=m2?qry1(l1,r1,2*i,l2,m2):(int)-1, r1>m2?qry1(l1,r1,2*i+1,m2+1,r2):(int)-1);
}

void upd2(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st2[i].mn=x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd2(l1,x,2*i,l2,m2);
    } else {
        upd2(l1,x,2*i+1,m2+1,r2);
    }
    st2[i].mn = max(st2[2*i].mn,st2[2*i+1].mn);
}

int qry2(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st2[i].mn;
    }
    int m2=(l2+r2)/2;
    return max(l1<=m2?qry2(l1,r1,2*i,l2,m2):(int)-1, r1>m2?qry2(l1,r1,2*i+1,m2+1,r2):(int)-1);
}

void solve() {
    cin >>n;
    int mx=-1;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        max_self(mx,a[i]);
    }
    upd1(0,0); upd2(0,0); upd1(n-1,0); upd2(n-1,0);
    for(int i=1;i<=n-2;i++) {
        int v[3] = {a[i-1],a[i],a[i+1]};
        sort(v,v+3);
        if(a[i]==v[2]) {
            ans[0][i] = v[1];
            ans[1][i] = v[2]; // 0 ambil max
        } else if(a[i]==v[0]) {
            ans[0][i] = v[0];
            ans[1][i] = v[1];
        } else {
            ans[0][i] = v[1]; // 1 ambil min
            ans[1][i] = v[1];
        }
        upd1(i,ans[0][i]);
        upd2(i,ans[1][i]);
    }
    for(int i=n;i>=1;i--) {
        int temp=-1;
        if(i>=3) {
            if(i%2==1) {
                temp = qry1(i/2,n-1-(i/2));
            } else {
                temp = qry2((i-1)/2,n-1-((i-1)/2));
            }
        } else {
            temp = mx;
        }
        if(i==n) {
            cout <<temp;
        } else if(i!=1) {
            cout <<" " <<temp;
        } else if(i==1) {
            cout <<" " <<temp <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
