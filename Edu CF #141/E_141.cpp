#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
int a[mxn],b[mxn];

ll x[mxn];

struct node {
    ll mn, s, lz;
} st[1<<19];

void app(int i, ll x, int l2, int r2) {
    st[i].mn +=x;
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

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i]; a[i]--;
    }
    for(int i=0;i<n;i++) {
        cin >>b[i]; b[i]--;
    }
    for(int i=1;i<=n;i++) {
        upd(i,0);
    }
    for(int i=0;i<n;i++) {
        if(b[i]>=a[i]) continue;
        for(int j=1,la;j<=b[i];j=la+1) {
            la = b[i] /(b[i]/j);
            int l=j, r=la;
            int ans=-1;
            while(l<=r) {
                int mid = (l+r)/2;
                if(b[i]/mid != a[i]/mid) {
                    ans = mid;
                    l = mid+1;   
                } else {
                    r = mid-1;
                }
            }
            if(ans!=-1) {
                // mark l..ans
                // cout <<"he\n";
                // cout <<j <<' ' <<ans <<'\n';
                // cout <<la <<"\n";
                upd2(j,ans,1);
            }
        }
        if(b[i]+1<=a[i]) upd2(b[i]+1,a[i],1);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if(qry(i,i)==0) {
            ans.push_back(i);
        }
    }
    cout <<sz(ans) <<"\n";
    for(int i=0;i<sz(ans);i++) {
        if(i==0) {
            cout <<ans[i];
        } else {
            cout <<" " <<ans[i];
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}