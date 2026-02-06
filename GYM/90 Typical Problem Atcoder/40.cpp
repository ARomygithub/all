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

const int mxn=1e2;
int n,w;
int a[mxn];

void solve() {
    cin >>n >>w;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<set<int>> vs(n);
    rep(i,0,n) {
        int ki; cin >>ki;
        rep(j,0,ki) {
            int cij; cin >>cij; cij--;
            vs[cij].insert(i);
        }
    }
    rep(i,0,n) {
        set<int> ad;
        for(auto si : vs[i]) {
            for(auto j : vs[si]) {
                ad.insert(j);
            }
        }
        for(auto adi : ad) {
            vs[i].insert(adi);
        }
    }
    int ans = 0;
    set<int> s;
    bool ok = 1;
    while(ok) {
        ok = 0;
        rep(i,0,n) {
            if(s.count(i)) continue;
            set<int> ad;
            int cur = 0;
            ad.insert(i);
            cur += a[i]-w;
            for(auto si : vs[i]) {
                if(s.count(si)) continue;
                ad.insert(si);
                cur += a[si]-w;
            }
            if(cur>=0) {
                ok = 1;
                ans += cur;
                for(auto adi : ad) {
                    s.insert(adi);
                }
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}