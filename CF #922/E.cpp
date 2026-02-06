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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e3;
int n,t;
int perm[mxn];

char ask(int i) {
    cout <<"? " <<i+1 <<"\n" <<flush;
    char ret; cin >>ret;
    if(ret=='-') {
        exit(0);
    }
    return ret;
}

void slv(int lo, int hi) {
    if(lo>=hi) return;
    random_shuffle(perm+lo, perm+hi+1);
    int piv = perm[lo + (rand()%(hi-lo+1))];
    while(ask(piv)!='=') {;}
    vector<int> vlo, vhi;
    rep(i,lo,hi+1) {
        if(perm[i]==piv) continue;
        char ret = ask(perm[i]);
        if(ret=='>') {
            vhi.push_back(perm[i]);
        } else {
            vlo.push_back(perm[i]);
        }
        if(i<hi-1 || (i==hi-1 && perm[hi]!=piv)) ask(piv);
    }
    perm[sz(vlo)+lo] = piv;
    rep(i,lo,lo+sz(vlo)) {
        perm[i] = vlo[i-lo];
    }
    rep(i,0,sz(vhi)) {
        perm[lo+sz(vlo)+1+i] = vhi[i];
    }
    slv(lo,lo+sz(vlo)-1);
    slv(lo+sz(vlo)+1,hi);
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        perm[i] = i;
    }
    slv(0,n-1);
    vector<int> ans(n);
    rep(i,0,n) {
        ans[perm[i]] = i+1;
    }
    cout <<"! ";
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
    cout <<flush;
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