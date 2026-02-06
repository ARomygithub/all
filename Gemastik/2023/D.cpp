#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,k,b;
int h[mxn], p[mxn];
vector<int> cs(mxn,1);
int ct[mxn];

int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return 0;
    }
    if (cs[x]>cs[y]) swap(x,y);
    h[y] = min(h[y],h[x]);
    cs[y]=cs[x]+cs[y];
    p[x]=y;
    return 1;
    //update cs juga
}

void solve() {
    cin >>n >>k >>b;
    for(int i=0;i<n;i++) {
        cin >>h[i];
    }
    iota(p,p+n,0);
    for(int i=0;i<k;i++) {
        int u,v; cin >>u >>v; u--,v--;
        join(u,v);
    }
    set<int> s;
    int mn=1e9;
    int imn = -1;
    ll ans=0;
    for(int i=0;i<n;i++) {
        int x = find(i);
        s.insert(x);
        ct[x]++;
        ans +=1ll*h[x];
        if(h[x]<mn) {
            mn = h[x];
            imn = x;
        }
    }

    vector<ll> v;
    for(int x : s) {
        if(x!=imn) {
            v.push_back(1ll*ct[x]*(h[x]-mn));
        }
    }
    sort(v.begin(),v.end(),greater<ll>());
    for(int i=0;i<min(b,sz(v));i++) {
        ans -=v[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}