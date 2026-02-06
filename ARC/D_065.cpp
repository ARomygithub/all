#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,k,l;
int pa[mxn+1],pb[mxn+1],csa[mxn+1],csb[mxn+1];

int find1(int x) {
    return x==pa[x]?x:pa[x]=find1(pa[x]);
}

void join1(int x, int y) {
    if((x=find1(x))==(y=find1(y))) {
        return;
    }
    if(csa[x]>csa[y]) swap(x,y);
    pa[x] = y;
    csa[y] += csa[x];
}

int find2(int x) {
    return x==pb[x]?x:pb[x]=find2(pb[x]);
}

void join2(int x, int y) {
    if((x=find2(x))==(y=find2(y))) {
        return;
    }
    if(csb[x]>csb[y]) swap(x,y);
    pb[x] = y;
    csb[y] += csb[x];
}

void solve() {
    cin >>n >>k >>l;
    iota(pa,pa+n,0);
    iota(pb,pb+n,0);
    fill(csa,csa+n,1);
    fill(csb,csb+n,1);
    rep(i,0,k) {
        int u,v; cin >>u >>v; u--,v--;
        join1(u,v);
    }
    rep(i,0,l) {
        int u,v; cin >>u >>v; u--,v--;
        join2(u,v);
    }
    vector v(n, map<int,int>());
    rep(i,0,n) {
        int pai = find1(i);
        int pbi = find2(i);
        v[pai][pbi]++;
    }
    rep(i,0,n) {
        int pai = find1(i);
        int pbi = find2(i);
        cout <<v[pai][pbi] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}