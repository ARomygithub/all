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
const ll mod = 1e9+7;
int n,q,t;
// ll a[mxn];
int fp[mxn+1];
vi ct[mxn+1];

void solve() {
    cin >>n >> q;
    set<int> tocl;
    vector<map<int,int>> v(n);
    ll ans = 1;
    auto ad = [&](int i, int p0) -> void {
        int cur = v[i][p0];
        if(cur<sz(ct[p0])) {
            ct[p0][cur]++;
        } else {
            ct[p0].push_back(1);
        }
        tocl.insert(p0);
        v[i][p0]++;
        if(ct[p0][cur]==n) {
            ans = ans*p0%mod;
        }
    };
    rep(i,0,n) {
        int ai; cin >>ai;
        while(ai>1) {
            ad(i,fp[ai]);
            ai /= fp[ai];
        }
    }
    while(q--) {
        int i,x; cin >>i >>x; i--;
        while(x>1) {
            ad(i, fp[x]);
            x /= fp[x];
        }
        cout <<ans <<"\n";
    }
    for(auto cli: tocl) {
        ct[cli].clear();
    }
}

void init() {
    fp[1] = 1;
    bitset<mxn+1> iscomp;
    rep(i,2,mxn+1) {
        // cout <<i <<endl;
        if(!iscomp[i]) {
            fp[i] = i;
            for(ll j = 1ll*i*i;j<=mxn;j+=i) {
                iscomp[j] = 1;
                if(fp[j]==0) {
                    fp[j] = i;
                } else {
                    min_self(fp[j], i);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    init();
    while(t--) {
        solve();
    }
}