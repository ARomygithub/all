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
const char cc[3] = {'R','G','B'};
int t;

void solve() {
    vector<pii> v(3);
    rep(i,0,3) {
        cin >>v[i].fi;
        v[i].se = i;
    }
    sort(all(v));
    vector<char> c(3);
    rep(i,0,3) {
        c[i] = cc[v[i].se];
    }
    min_self(v[2].fi, v[0].fi+v[1].fi+1);
    string ans = "";
    if((v[2].fi - (v[1].fi-v[0].fi))%2) {
        ans += c[2];
        v[2].fi--;
    }
    int tmp = v[1].fi-v[0].fi;
    rep(i,0,tmp) {
        ans += c[1];
        ans += c[2];
    }
    v[2].fi -= tmp;
    v[1].fi -= tmp;
    tmp = v[2].fi/2;
    bool akhir1 = tmp==0;
    rep(i,0,tmp) {
        ans += c[1];
        ans += c[2];
    }
    rep(i,0,tmp) {
        ans += c[0];
        ans += c[2];
    }
    v[2].fi -= tmp*2;
    assert(v[2].fi==0);
    v[1].fi -= tmp;
    v[0].fi -= tmp;
    rep(i,0,v[1].fi) {
        if(akhir1) {
            ans += c[1];
            ans += c[0];
        } else {
            ans += c[0];
            ans += c[1];
        }
    }
    assert(v[0].fi==v[1].fi);
    rep(i,3,sz(ans)) {
        assert(ans[i]!=ans[i-3]);
    }
    cout <<ans <<"\n";
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