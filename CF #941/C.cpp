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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vector<pii> v;
    for(int i=0;i<sz(s);) {
        int ct = 0;
        int j = i;
        while(j<sz(s) && s[j]==s[i]) {
            ct++;
            j++;
        }
        v.push_back({s[i]-'0',ct});
        i = j;
    }
    int l = 0, r = sz(v)-1;
    int lrng = -1;
    vector<int> vl(sz(v),1e9), vr(sz(v),sz(v)-1);
    rep(i,1,sz(v)-1) {
        // vl[i] = vl[i-1];
        if(i>lrng && v[i].se>1 && (v[i].se%2)==0) {
            lrng = i+(i-l-1);
            l = i;
            vl[i] = lrng;
            max_self(r, lrng);
        }
    }
    // lrng = sz(v);
    // per(i,sz(v)-1,0) {
    //     vr[i] = vr[i+1];
    //     if(i<lrng && v[i].se>1 && (v[i].se%2)==0) {
    //         lrng = i - (r-i);
    //         r = i;
    //         vr[i] = r;
    //     }
    // }
    // int ans = sz(v);
    // rep(i,0,sz(v)) {

    //     min_self(ans, )
    // }
    cout <<r-l+1 <<"\n";
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