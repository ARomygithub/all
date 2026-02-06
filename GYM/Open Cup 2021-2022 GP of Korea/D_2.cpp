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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e5,tes=1e4;
const ll moda[5]={998244353,(ll)(1e9+7),988659953,988666163,988666423};
int n,d;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>d >>n;
    vector<pll> ve(d);
    vector rnd(2, vector<ll>(n));
    ll mod[2] = {moda[rng()%5], moda[rng()%5]};
    rep(i,0,2) {
        rep(j,0,n) {
            do {
                rnd[i][j] = rng()%mod[i];
            } while(rnd[i][j]<tes);
        }
    }
    map<int,ll> mpr;
    rep(i,0,d) {
        vector<ipii> ed(n-1);
        rep(j,0,n-1) {
            int u,v,c; cin >>u >>v >>c; u--,v--;
            ed[j] = {c,{u,v}};
        }
        sort(ed.begin(),ed.end(),greater<ipii>());
        rep(k,0,2) {
            ll h = 0;
            vector<int> p(n);
            vector<int> cs(n);
            vector<ll> val(n);
            rep(j,0,n) {
                val[j] = rnd[k][j];
            }
            iota(p.begin(),p.end(),0);
            fill(cs.begin(),cs.end(),1);
            function<int(int)> find;
            find = [&](int x) -> int {
                return x==p[x]?x:p[x]=find(p[x]);
            };
            auto join = [&](int x, int y, int z) -> void {
                if((x=find(x))==(y=find(y))) {
                    return;
                }
                if(cs[x]>cs[y]) swap(x,y);
                p[x] = y;
                cs[y] += cs[x];
                if(!mpr.count(z)) {
                    ll temp;
                    do {
                        temp = rng()%mod[k];
                    } while(temp<=tes);
                    mpr[z] = temp;
                }
                h = (h + val[x]*val[y]%mod[k]*mpr[z]%mod[k])%mod[k];
                val[y] = (val[y]+val[x])%mod[k];
            };
            for (auto [z,uv]: ed) {
                auto [u,v] = uv;
                join(u,v,z);
            }
            if(k==0) {
                ve[i].fi = h;
            } else {
                ve[i].se = h;
            }
        }
    }
    map<pll,int> mp;
    per(i,d-1,-1) {
        mp[ve[i]] = i+1;
    }
    rep(i,0,d) {
        cout <<mp[ve[i]] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}