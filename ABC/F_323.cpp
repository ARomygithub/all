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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
pll a,b,c;

ll aToB(pll ai, pll bi) {
    ll ret = abs(ai.fi-bi.fi)+abs(ai.se-bi.se);
    if((ai.fi==bi.fi && ai.fi==b.fi && min(ai.se,bi.se)<b.se && max(ai.se,bi.se)>b.se) || (ai.se==bi.se && ai.se==b.se && min(ai.fi,bi.fi)<b.fi && max(ai.fi,bi.fi)>b.fi)) {
        ret +=2;
    }
    return ret;
}

ll aToC(int i) {
    ll ret = 0;
    if(i==0) {
        ret += aToB(a, {b.fi,b.se+1});
        // cout <<ret <<"\n";
        if(c.se<b.se) {
            ret += b.se-c.se;
            // cout <<ret <<"\n";
            if(b.fi!=c.fi) {
                ret +=2;
                ret += abs(b.fi-c.fi);
            }
            // cout <<ret <<"\n";
        } else {
            return 2e18;
        }
    } else if(i==1) {
        ret += aToB(a, {b.fi+1,b.se});
        if(c.fi<b.fi) {
            ret += b.fi-c.fi;
            if(b.se!=c.se) {
                ret +=2;
                ret += abs(b.se-c.se);
            }
        } else {
            return 2e18;
        }
    } else if(i==2) {
        ret += aToB(a, {b.fi,b.se-1});
        if(c.se>b.se) {
            ret += c.se-b.se;
            if(b.fi!=c.fi) {
                ret +=2;
                ret += abs(b.fi-c.fi);
            }
        } else {
            return 2e18;
        }
    } else {
        ret += aToB(a, {b.fi-1,b.se});
        if(c.fi>b.fi) {
            ret += c.fi-b.fi;
            if(b.se!=c.se) {
                ret +=2;
                ret += abs(b.se-c.se);
            }
        } else {
            return 2e18;
        }
    }
    return ret;
}

void solve() {
    cin >>a.fi >>a.se >>b.fi >>b.se >>c.fi >>c.se;
    ll ans = 2e18;
    rep(i,0,4) {
        min_self(ans, aToC(i));
        // cout <<aToC(i) <<"\n";
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}