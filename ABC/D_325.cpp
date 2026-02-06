#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n;
vector<pll> v;

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        ll t,d; cin >>t >>d;
        v.push_back({t+d,t});
    }
    sort(v.begin(),v.end());
    ll ans=0;
    set<pll> s;
    ll infi = 2e18;
    s.insert({infi,1});
    for(int i=0;i<n;i++) {
        auto [ed,st] = v[i];
        auto it = s.lower_bound(make_pair(st,0ll));
        if(it!=s.end()) {
            auto [edi,sti] = *it;
            if(sti<=ed) {
                ll x = max(sti,st);
                s.erase(it);
                ans++;
                if(sti<x) {
                    s.insert({x-1,sti});
                } 
                if(edi>x) {
                    s.insert({edi,x+1});
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