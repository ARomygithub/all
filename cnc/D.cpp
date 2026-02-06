#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define piii pair<pii,int>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5+2;
int n,m;
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
    st[i].mn = max(st[2*i].mn,st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mn;
    }
    int m2=(l2+r2)/2;
    return max(l1<=m2?qry(l1,r1,2*i,l2,m2):(int)0, r1>m2?qry(l1,r1,2*i+1,m2+1,r2):(int)0);
    // return (l1<=m2?qry(l1,r1,2*i,l2,m2):0) + (r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0);
}

void solve() {
    cin >>m;
    n = mxn;
    vector<piii> v(m);
    for(int i=0;i<m;i++) {
        cin >>v[i].fi.fi >>v[i].fi.se >>v[i].se;
    }
    sort(v.begin(),v.end(),greater<piii>());
    ll ans=0;
    for(int i=0;i<m;) {
        int j = i;
        while(true) {
            ll temp = qry(v[j].fi.se+1,mxn)+v[j].se;
            max_self(ans,temp);
            max_self(x[v[j].fi.se],temp);
            if(j+1==m || v[j+1].fi.fi<v[j].fi.fi) {
                break;
            } else {
                j++;
            }
        }

        // cout <<v[i].fi.fi <<" " <<v[i].fi.se <<" " <<v[i].se <<" " <<x[v[i].fi.se] <<"\n";
        while(i<=j) {
            upd(v[i].fi.se,x[v[i].fi.se]);
            i++;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}