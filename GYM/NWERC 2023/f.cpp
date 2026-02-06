#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

ll a,b,c,d;
using pll = pair<ll,ll>;
const ll mxa = 1e18;

void solve() {
    cin >>a >>b >>c >>d;
    string sta = to_string(a), stb = to_string(b);
    set<ll> sb;
    function<void(ll,int)> dfs;
    dfs = [&](ll cur, int pos) -> void {
        if(pos>=sz(stb)) return;
        ll nx = cur*10 + (stb[pos]-'0');
        sb.insert(nx);
        dfs(nx, pos+1);
        dfs(cur, pos+1);
    };
    dfs(0,0);
    bool ok = 0;
    pll ans;
    vi cta(10,0), ctb(10,0);
    ll ua = a, ub = b;
    while(ua) {
        cta[ua%10]++;
        ua /= 10;
    }
    while(ub) {
        ctb[ub%10]++;
        ub /= 10;
    }
    auto cek = [&](ll x, ll y) -> bool {
        vi ctx(10,0), cty(10,0);
        while(x) {
            ctx[x%10]++;
            x /= 10;
        }
        while(y) {
            cty[y%10]++;
            y /= 10;
        }
        rep(i,0,10) {
            if((cta[i]-ctx[i])!=(ctb[i]-cty[i])) return false;
        }
        return true;
    };
    function<void(ll,int)> dfs2;
    dfs2 = [&](ll cur, int pos) -> void {
        if(pos>=sz(sta)) return;
        if(ok) return;
        ll nx = cur*10 + (sta[pos]-'0');
        ll u = c;
        u /= __gcd(u, nx);
        u /= __gcd(u, d);
        if(u==1 && nx>0) {
            u = c;
            ll bwh = nx/__gcd(u,nx);
            u /= __gcd(u,nx);
            ll tmp = d/__gcd(d,u);
            if(mxa/bwh >= tmp) {
                bwh *= tmp;
                if(sb.count(bwh) && cek(nx,bwh)) {
                    ok = 1;
                    ans = {nx,bwh};
                    return;
                }
            }
        }
        dfs2(nx, pos+1);
        dfs2(cur, pos+1);
    };
    dfs2(0,0);
    if(ok) {
        cout <<"possible\n";
        cout <<ans.fi <<" " <<ans.se <<"\n";
    } else {
        cout <<"impossible\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}