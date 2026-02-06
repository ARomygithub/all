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
int n,t;

int ask(vi& v) {
    cout <<"? " <<sz(v) <<" ";
    rep(i,0,sz(v)) {
        cout <<v[i] <<" \n"[i==sz(v)-1];
    }
    cout <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    vi a(n*2,0);
    vi v,v2;
    rep(i,1,n*2+1) {
        v.push_back(i);
        int ret = ask(v);
        if(ret) {
            a[i-1] = ret;
            v.pop_back();
            v2.push_back(i);
        }
    }
    rep(i,0,n*2) {
        if(a[i]==0) {
            v2.push_back(i+1);
            int ret = ask(v2);
            a[i] = ret;
            v2.pop_back();
        }
    }
    cout <<"! ";
    rep(i,0,n*2) {
        cout <<a[i] <<" \n"[i==n*2-1];
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