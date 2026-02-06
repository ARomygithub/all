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

const int mxn=1e5,mxa=1e9;
int n;

void solve() {
    cin >>n;
    set<pii> s;
    s.insert({1,mxa});
    ll ans = 0;
    vector<pii> toAdd, toEr;
    auto add = [&](pii it, int li, int ri) -> void {
        if(ri<it.fi || li>it.se) return;
        int lii = max(li,it.fi), rii = min(ri,it.se);
        ans += 1ll*(rii+lii)*(rii-lii+1)/2;
        if(it.fi<lii) {
            toAdd.push_back({it.fi,lii-1});
        }
        if(rii<it.se) {
            toAdd.push_back({rii+1,it.se});
        }
        toEr.push_back(it);
    };
    rep(i,0,n) {
        int li,ri; cin >>li >>ri;
        if(sz(s)==0) continue;
        auto it = s.upper_bound({li,mxa+1});
        if(it!=s.begin()) {
            it--;
        }
        while(it!=s.end()) {
            add(*it, li, ri);
            if(it->se >= ri) break;
            it++;
        }
        for(auto eri: toEr) {
            s.erase(eri);
        }
        for(auto adi : toAdd) {
            s.insert(adi);
        }
        toEr.clear(); toAdd.clear();
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}