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

const ll mxn=1e15,mxb=50;
ll n;
int q;
ll dp[mxb];

ll F(ll x) {
    ll u = x;
    ll ret = 0;
    per(i,mxb-1,-1) {
        if((x>>i)&1) {
            ret += dp[i];
            u -= (1ll<<i);
            if(u==0) {
                break;
            }
            ret += u;
        }
    }
    return ret;
}

vector<pll> v;
ll par(ll x) {
    auto it = upper_bound(v.begin(),v.end(), (pll){x,(ll)(1e18)});
    // cout <<(*it).fi <<" " <<(*it).se <<endl;
    it--;
    // cout <<(*it).fi <<" " <<(*it).se <<endl;
    it--;
    // cout <<(*it).fi <<" " <<(*it).se <<endl;
    ll li = it->fi;
    ll ri = it->se;
    ll p = -1;
    ll l=li, r = ri;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll temp = F(li-1);
        ll awl = (F(mid-1)-temp)+ri+1;
        ll akh = (F(mid)-temp)+ri;
        if(x>=awl && x<=akh) {
            p = mid;
            break;
        } else if(x<awl) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    // cout <<x <<" " <<p <<endl;
    return p;
}

void solve() {
    cin >>n >>q;
    v.push_back({1ll,1ll});
    while(true) {
        ll li = v.back().se+1;
        ll ri = v.back().se+F(v.back().se)-F(v.back().fi-1);
        if(li>mxn) {
            break;
        } else {
            v.push_back({li,ri});
        }
        // cout <<li <<" " <<ri <<endl;
    }
    // cout <<sz(v) <<endl;
    while(q--) {
        ll a,b; cin >>a >>b;
        int ret = 0;
        while(a!=b) {
            if(a<b) {
                b = par(b);
                ret++;
            } else {
                a = par(a);
                ret++;
            }
        }
        cout <<ret <<"\n";
    }
}

void init() {
    rep(i,0,mxb) {
        dp[i] = 1;
        if(i>0) {
            dp[i] += (1ll<<(i-1))*i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}