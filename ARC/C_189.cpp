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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,x;
int p[mxn],q[mxn],a[mxn],b[mxn];
vi adjp[mxn],adjq[mxn];
vi lfp,lfq;

void dfsp(int u, int pr=-1) {
    int ad = 0;
    for(int v: adjp[u]) {
        if(v==pr) continue;
        dfsp(v);
        ad += a[v];
    }
    if(ad==0) {
        lfp.push_back(u);
    }
    a[u] += ad;
}

void dfsq(int u, int pr=-1) {
    int ad = 0;
    for(int v: adjq[u]) {
        if(v==pr) continue;
        dfsq(v);
        ad += b[v];
    }
    if(a[u]>0 && ad==0) {
        lfq.push_back(u);
    }
    b[u] += ad;
}


void solve() {
    cin >>n >>x; x--;
    set<int> sa,sb;
    rep(i,0,n) {
        cin >>a[i];
        if(a[i]>0) {
            sa.insert(i);
        }
    }
    rep(i,0,n) {
        cin >>b[i];
        if(b[i]>0) {
            sb.insert(i);
        }
    }
    rep(i,0,n) {
        cin >>p[i]; p[i]--;
        adjp[p[i]].push_back(i);
    }
    rep(i,0,n) {
        cin >>q[i]; q[i]--;
        adjq[q[i]].push_back(i);
    }
    dfsp(x,-1);
    dfsq(x, -1);
    int ans = 0;
    set<int> canda,candb;
    while(true) {
        bool ok = 1;

    }
    if(sz(sa)==1 && sz(sb)==1 && (*sa.begin())==x && (*sb.begin())==x) {
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}