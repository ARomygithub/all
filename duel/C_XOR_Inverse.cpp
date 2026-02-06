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

const int mxn=3e5;
int n,t;
int a[mxn];

using ps = array<set<int>,2>;
using piii = pair<pii,int>;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = 0;
    ll cta = 0;
    rep(bit,0,30) {
        // map<int,ps> mp;
        vector<piii> v;
        rep(i,0,n) {
            int pr = a[i]>>(bit+1);
            v.push_back({{pr,(a[i]>>bit)&1}, i});
        }
        sort(all(v));
        ll le = 0, ri = 0;
        for(int i=0;i<n;) {
            int j = i;
            while(j<n && v[j].fi.fi==v[i].fi.fi) {
                j++;
            }
            vector vst(2, vi());
            rep(k,i,j) {
                vst[v[k].fi.se].push_back(v[k].se);
            }
            ll ct = 0;
            int tmp = 0;
            auto it = vst[0].begin();
            auto it2 = vst[1].begin();
            while(it != vst[0].end()) {
                while(it2!=vst[1].end() && (*it2)<(*it)) {
                    tmp++;
                    it2++;
                }
                ct += tmp;
                it++;
            }
            le += ct;
            ri += (1ll*sz(vst[0])*sz(vst[1])) - ct;

            i = j;
        }
        if(le> ri) {
            ans += (1<<bit);
        }
        cta += min(le,ri);
    }
    cout <<cta <<" " <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}