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

const int mxn=1e5;
int n,m;
int a[mxn];

void solve() {
    cin >>n;
    vector<pii> v(n);
    rep(i,0,n) {
        cin >>v[i].fi >>v[i].se;
    }
    cin >>m;
    rep(i,0,m) {
        cin >>a[i];
    }
    sort(v.begin(),v.end(), [&](pii x, pii y)-> bool  {
        return pii{x.fi,-x.se} < pii{y.fi,-y.se};
    });
    set<pii> s;
    int ri = 0;
    rep(i,0,sz(v)) {
        auto [l,r] = v[i];
        if(r>ri) {
            s.insert({l,r});
            ri = r;
            // cout <<l <<" " <<r <<endl;
        }
    }
    int ans = 0;
    int le=a[0]; ri=a[0];
    auto chk = [&](int l, int r) -> bool {
        auto it = s.lower_bound({l,2e9});
        if(it!=s.begin()) {
            it--;
            auto [la,ra] = *it;
            return l>=la&&r<=ra;
        }
        return false;
    };
    rep(i,0,m) {
        min_self(le,a[i]);
        max_self(ri, a[i]);
        if(!chk(le,ri)) {
            ans++;
            le = a[i],ri=a[i];
            // cout <<le <<" " <<ri <<endl;
            if(!chk(le,ri)) {
                cout <<"-1\n";
                return;
            }
        } 
    }
    // ans++;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}