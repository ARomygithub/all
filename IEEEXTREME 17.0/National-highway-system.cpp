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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=4e5+5;
int n;
vector<ipii> edges; 
int cs[mxn],p[mxn];

int find(int x) {
    return (x^p[x])==0?x:(p[x]=find(p[x]));
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return 0;
    }
    if(cs[x]>cs[y]) swap(x,y);
    p[x] = y;
    cs[y] +=cs[x];
    return 1;
}

void solve() {
    cin >>n;
    map<string,int> mp;
    int m=0;
    rep(i,0,n) {
        string ni,nj; cin >>ni >>nj;
        if(!mp.count(ni)) {
            mp[ni] = m++;
        }
        if(!mp.count(nj)) {
            mp[nj] = m++;
        }
        int ci; cin >>ci;
        edges.push_back({ci,{mp[ni],mp[nj]}});
    }
    sort(edges.begin(),edges.end());
    iota(p,p+m,0);
    fill(cs,cs+m,1);
    vector<bool> status(sz(edges),0);
    int ctc = m;
    for(int i=0;i<sz(edges);) {
        int ci = edges[i].fi;
        int j=i;
        while(j<sz(edges) && edges[j].fi==ci) {
            j++;
        }
        for(int ii=i;ii<j;ii++) {
            int x = find(edges[ii].se.fi);
            int y = find(edges[ii].se.se);
            if(x!=y) {
                status[ii] = 1;
            }
        }
        for(int ii=i;ii<j;ii++) {
            if(join(edges[ii].se.fi,edges[ii].se.se)) {
                ctc--;
            }
        }
        i = j;
    }
    ll ans=0;
    if(ctc!=1) {
        cout <<"-1\n";
        return;
    }
    for(int i=0;i<sz(edges);i++) {
        if(status[i]) {
            ans +=edges[i].fi;
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