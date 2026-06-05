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

const int mxn=1e4;
int n,t;

int ask(int i, int j) {
    cout <<"? " <<i+1 <<" " <<j+1 <<"\n" <<flush;
    int ret; cin >>ret;
    if(ret==-1) exit(0);
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n-1) {
        int ret = ask(i*2,i*2+1);
        if(ret==1) {
            cout <<"! " <<i*2+1 <<"\n" <<flush;
            return;
        }
    }
    int ret0 = ask(0,n*2-2), ret1 = ask(1,n*2-2);
    int ans = -1;
    if(ret0==0 && ret1==0) {
        ans = n*2;
    } else {
        ans = n*2-1;
    }
    cout <<"! " <<ans <<"\n" <<flush;
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