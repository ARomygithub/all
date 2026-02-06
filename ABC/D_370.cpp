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
int n,m,q;

void solve() {
    cin >>n >>m >>q;
    vector<set<int>> vr(n),vc(m);
    rep(i,0,n) {
        rep(j,0,m) {
            vr[i].insert(j);
            vc[j].insert(i);
        }
    }
    while(q--) {
        int ri,ci; cin >>ri >>ci; ri--,ci--;
        if(vr[ri].count(ci)) {
            vr[ri].erase(ci);
            vc[ci].erase(ri);
        } else {
            auto it = vr[ri].lower_bound(ci);
            int l=-1,r=-1,u=-1,d=-1;
            if(it!=vr[ri].begin()) {
                auto it2 = it; it2--;
                l = *it2;
            }
            if(it!=vr[ri].end()) {
                r = *it;
            }
            it = vc[ci].lower_bound(ri);
            if(it!=vc[ci].begin()) {
                auto it2 = it; it2--;
                u = *it2;
            }
            if(it!=vc[ci].end()) {
                d = *it;
            }
            if(l!=-1) {
                vr[ri].erase(l);
                vc[l].erase(ri);
            }
            if(r!=-1) {
                vr[ri].erase(r);
                vc[r].erase(ri);
            }
            if(u!=-1) {
                vc[ci].erase(u);
                vr[u].erase(ci);
            }
            if(d!=-1) {
                vc[ci].erase(d);
                vr[d].erase(ci);
            }
        }
    }
    int ans = 0;
    rep(i,0,n) {
        ans += sz(vr[i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}