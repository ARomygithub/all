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

const int mxn=1e3;
int n;

ll ask(int qt, int i, int j, int k) {
    cout <<qt <<" " <<i <<" " <<j <<" " <<k <<"\n" <<flush;
    ll ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    int nxt=2;
    rep(i,3,n+1) {
        ll ret = ask(2,1,nxt,i);
        if(ret==-1) {
            nxt = i;
        }
    }
    vector<ll> d(n+1,0);
    rep(i,2,n+1) {
        if(i==nxt) continue;
        d[i] = ask(1,1,nxt,i);
    }
    ll idmx=-1,mx=-1;
    rep(i,1,n+1) {
        if(d[i]>mx) {
            mx = d[i];
            idmx = i;
        }
    } 
    vector<pll> f,b;
    rep(i,2,n+1) {
        if(i==nxt || i==idmx) continue;
        ll ret = ask(2,1,idmx,i);
        if(ret==1) {
            b.push_back({d[i],i});
        } else {
            f.push_back({d[i],i});
        }
    }
    sort(b.begin(),b.end());
    sort(f.begin(),f.end());
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(nxt);
    rep(i,0,sz(f)) {
        ans.push_back(f[i].se);
    }
    ans.push_back(idmx);
    per(i,sz(b)-1,-1) {
        ans.push_back(b[i].se);
    }
    cout <<"0 ";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
    cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}