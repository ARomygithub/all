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
int n,m,t;
int a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> lr(m),rl(m);
    rep(i,0,m) {
        cin >>lr[i].fi >>lr[i].se; lr[i].fi--, lr[i].se--;
        rl[i] = {-lr[i].se,-lr[i].fi};
    }
    sort(all(lr));
    sort(all(rl));
    int ilr = 0;
    vi jauhlr(n,-1);
    rep(i,0,n) {
        while(ilr<m && lr[ilr].fi<=i) {
            max_self(jauhlr[i],(lr[ilr].se));
            ilr++;
        }
        if(i) {
            max_self(jauhlr[i], jauhlr[i-1]);
        }
    }
    vi jauhrl(n,n);
    int irl = 0;
    per(i,n-1,-1) {
        while(irl<m && (rl[irl].fi)*-1 >=i) {
            min_self(jauhrl[i],rl[irl].se*-1); 
            irl++;
        }
        if(i+1<n) {
            min_self(jauhrl[i], jauhrl[i+1]);
        }
    }
    // 1.inf, 2. r min. ke berapa
    vi r(n,-1);
    map<int,vi> idx;
    rep(i,0,n) {
        idx[a[i]].push_back(i);
    }
    int linf = n, rm = -1;
    for(auto& [val,ve]: idx) {
        rep(i,0,sz(ve)) {
            if(i+1<sz(ve) && jauhlr[ve[i]]>=ve[i+1]) {
                min_self(linf, ve[i+1]+1);
            }
        }
        per(i,sz(ve)-1,-1) {
            if(i-1>=0 && jauhrl[ve[i]]<=ve[i-1]) {
                max_self(rm,ve[i-1]);
            }
        }
    }
    rep(i,linf,n) {
        r[i] = 1e9;
    }
    int ans = n;
    rep(i,0,linf) {
        r[i] = rm;
        auto& ve = idx[a[i]];
        auto it = upper_bound(all(ve),jauhlr[i]);
        if(it!=ve.begin()) {
            it--;
            if((*it)>i) {
                max_self(rm, (*it));
            }
        }
        if(r[i]>=i) {
            min_self(ans, r[i]-i+1);
        } else {
            ans = 0;
            break;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}