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
int n,m,t;

void solve() {
    cin >>n >>m;
    multiset<int> ms1,ms2;
    ll s1 = 0, s2=0;
    rep(i,0,n) {
        int ai; cin >>ai;
        ms1.insert(ai);
        s1 += ai;
    }
    rep(i,0,m) {
        int bi; cin >>bi;
        ms2.insert(bi);
        s2 += bi;
    }
    if(s1!=s2) {
        cout <<"No\n";
        return;
    }
    while(sz(ms2) && sz(ms1)) {
        auto it2 = ms2.begin();
        auto it1 = ms1.begin();
        if((*it2)<(*it1)) {
            cout <<"No\n";
            return;
        }
        if(ms1.count(*it2)) {
            ms1.erase(ms1.find(*it2));
            ms2.erase(it2);
        } else {
            int cur = *it2;
            ms2.erase(it2);
            int x = cur/2, y = cur-x;
            ms2.insert(x);
            ms2.insert(y);
        }
    }
    if(sz(ms1) || sz(ms2)) {
        cout <<"No\n";
    } else {
        cout <<"Yes\n";
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