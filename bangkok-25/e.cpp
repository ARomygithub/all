#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i= a; i < (b);i++)
#define per(i,a,b) for(int i= a; i > (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

auto compress_coords(auto &coords) {
    vi original;
    original.reserve(sz(coords));
    ranges::sort(coords);
    int idx = -1, prev = -1;
    for(auto &x: coords) {
        if(x != prev) {
            idx++;
            prev = x;
            original.push_back(x);
        }
        x.get() = idx;
    }
    return original;
}

const int mxn=100,mxm=1e4,mxq=1e5;
int n,m,q;
using pipi = pair<pii,pii>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using plii = pair<pli,int>;
using piil = pair<pii,ll>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

void solve() {
    cin >>n >>m >>q;
    vector<pipi> e(m);
    vector<reference_wrapper<int>> vw;
    rep(i,0,m) {
        int u,v,p,h; cin >>u >>v >>p >>h; u--,v--;
        e[i] = {{p,h},{u,v}};
        vw.push_back(ref(e[i].fi.fi));
    }
    auto values = compress_coords(vw);
    vector dp(n, vector(n, vector<pil>()));
    rep(i,0,n) {
        dp[i][i].push_back({0,0});
    }
    sort(all(e));
    rep(i,0,m) {
        auto& [ph,uv] = e[i];
        auto& [p,h] = ph;
        auto& [u,v] = uv;
        rep(le,0,n) {
            if(sz(dp[le][u])==0) continue;
            rep(ri,0,n) {
                if(sz(dp[v][ri])==0) continue;
                if(sz(dp[le][ri]) && dp[le][ri].back().fi==p) {
                    min_self(dp[le][ri].back().se, dp[le][u].back().se + h + dp[v][ri].back().se);
                } else {
                    pil cand = {p, dp[le][u].back().se+h+dp[v][ri].back().se};
                    if(sz(dp[le][ri]) && dp[le][ri].back().se <= cand.se) {
                        continue;
                    }
                    dp[le][ri].push_back(cand);
                }
            }
        }
    }
    vector v1(n, vector<pli>()); //hp
    vector<piil> v2;
    rep(i,0,n) {
        map<int,ll> mp;
        rep(j,0,n) {
            for(auto& [p,h]: dp[i][j]) {
                max_self(mp[p],h);
            }
        }
        vector<pil> v;
        for(auto& [p,h]: mp) {
            v.push_back({p,h});
        }
        sort(all(v));
        for(auto& [p,h]: v) {
            if(sz(v1[i]) && v1[i].back().fi <= h) {
                continue;
            }
            v1[i].push_back({h,p});
            v2.push_back({{p,i},h});
        }
        reverse(all(v1[i]));
    }
    sort(all(v2));
    vector<plii> v3;
    for(auto& [pu,h]: v2) {
        if(sz(v3) && v3.back().fi.fi <= h) {
            continue;
        }
        v3.push_back({{h,pu.fi},pu.se});
        // if(sz(v3)) {
        //     if(v3.back().fi.fi==h) continue;
        //     auto [ph,pp] = v3.back().fi;
        //     auto pu = v3.back().se;
        //     if(pii{pp,pu} )
        // }
    }
    reverse(all(v3));
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int u; ll h; cin >>u >>h; u--;
            auto it = upper_bound(all(v1[u]), pli{h,1e5});
            if(it!=v1[u].begin()) {
                it--;
                cout <<it->se <<"\n";
            } else {
                cout <<"-1\n";
            }
        } else {
            ll h; cin >>h;
            auto it = upper_bound(all(v3), plii{{h,1e5},(int)1e6});
            if(it!=v3.begin()) {
                it--;
                cout <<(it->se)+1 <<" " << it->fi.se <<"\n";
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    solve();
}