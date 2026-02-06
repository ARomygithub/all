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

const int mxn=1e5;
int t;

int ask(vi& v) {
    cout <<"? " <<sz(v) <<" ";
    rep(i,0,sz(v)) {
        cout <<v[i] <<" \n"[i==sz(v)-1];
    }
    cout <<flush;
    int ret; cin >>ret;
    if(ret==-1) exit(0);
    return ret;
}

void solve() {
    vi v;
    rep(i,0,mxn) {
        v.push_back(1);
    }
    int k = ask(v);
    if(k==mxn) {
        cout <<"! 1\n" <<flush;
        return;
    } else if(k==1) {
        cout <<"! " <<mxn <<"\n" <<flush;
        return;
    }
    int len = (mxn+k-1)/k;
    int ats = (mxn + k-2)/(k-1);
    v.clear();
    if(len+1==ats) {
        cout <<"! " <<len <<"\n" <<flush;
        return;
    }
    rep(i,len+1,ats) {
        v.push_back(len);
        v.push_back(i-len);
    }
    assert(sz(v)<=mxn);
    int ret = ask(v);
    int ans = (ats-len-1)*2 - ret + len;
    cout <<"! " <<ans <<"\n" <<flush;
    return;
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