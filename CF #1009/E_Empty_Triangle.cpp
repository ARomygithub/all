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

const int mxn=1500;
int n,t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int i, int j, int k) {
    cout <<"? " <<i <<" " <<j <<" " <<k <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

int rnd(int l, int r) {
    return l + (rng()%(r-l+1));
}

void solve() {
    cin >>n;
    vi v(3);
    vi a(n);
    iota(all(a),1);
    shuffle(all(a), rng);
    rep(i,0,3) {
        v[i] = a[i];
    }
    while(true) {
        int ret = ask(v[0],v[1],v[2]);
        if(ret==0) {
            cout <<"! " <<v[0] <<" " <<v[1] <<" " <<v[2] <<"\n" <<flush;
            return;
        } else if(ret==-1) {
            exit(0);
        }
        int cur = rnd(0,2);
        v[cur] = ret;
    }
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