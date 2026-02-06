#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define piii pair<pii,int>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod = 998244353;
int n;
vector<piii> e;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n;
    e.resize(n-1);
    for(int i=1;i<n;i++) {
        cin >>e[i-1].fi.fi >> e[i-1].fi.se >> e[i-1].se;
        e[i-1].fi.fi--, e[i-1].fi.se--;
    }
    ll ans = 0;
    for(int i=0;i<=27;i++) {
        vector<int> cs(n,1);
        vector<int> p(n);
        vector<bool> flag(n,true);
        function<int(int)> find;
        find = [&](int x) -> int {
            return x == p[x]? x : (p[x]=find(p[x]));
        };
        auto join = [&](int j) -> void {
            if(e[j].se&(1<<i)) {
                return;
            }
            int x = e[j].fi.fi, y = e[j].fi.se;
            if((x=find(x))==(y=find(y))) {
                return;
            }
            if(cs[x]>cs[y]) swap(x,y);
            p[x] = y;
            cs[y] +=cs[x];
            flag[y] = false;
        };
        iota(p.begin(),p.end(),0);
        for(int j=0;j<n-1;j++) {
            join(j);
        }
        ll ct = fastexpo(2ll,n)-1-n;
        map<int,int> mp;
        for(int j=0;j<n;j++) {
            int pi = find(j);
            if(!flag[pi]) {
                mp[pi] = cs[pi];
            }
        }
        for(auto [k,v]: mp) {
            ll temp = fastexpo(2ll,v)-1-v;
            ct = (ct-temp+mod)%mod;
        }
        ll temp = ct*(1ll<<i)%mod;
        ans = (ans+temp)%mod;
        // cout <<temp <<"\n";
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}