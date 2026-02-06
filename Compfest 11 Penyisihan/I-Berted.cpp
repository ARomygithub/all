#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<ll,ll>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5+1;
int n,m, ans[mxn],pref[mxn];
piii a[mxn];
pii b[mxn];
vector<int> p;

inline bool comp(const pii &L, const pii &R) {
    return L.se*R.fi > L.fi*R.se;
}

inline pii operator-(const pii& L, const pii &R) {
    return {L.fi-R.fi, L.se-R.se};
}

inline ll cross(const pii &L, const pii &R) {
    return L.fi*R.se-R.fi*L.se;
}

inline ll dot(const pii &L, const pii &R) {
    return L.fi*R.fi + L.se*R.se;
}

void solve() {
    cin >>m >>n;
    rep(i,0,m) {
        cin >>b[i].fi >>b[i].se;
    } 
    rep(i,0,n) {
        cin >>a[i].fi.fi >>a[i].fi.se;
        a[i].se = i;
    }
    sort(a,a+n);
    sort(b,b+m, comp);
    rep(i,0,n) {
        while(sz(p)>1 && cross(a[i].fi-a[p[sz(p)-2]].fi, a[p.back()].fi - a[p[sz(p)-2]].fi)<0) {
            p.pop_back();
        }
        p.push_back(i);
    }
    int l=0,r=0;
    rep(i,0,m) {
        while(l+1<sz(p) && dot(b[i], a[p[l]].fi) < dot(b[i], a[p[l+1]].fi)) {
            l++;
        }
        while(r+1<sz(p) && dot(b[i],a[p[r]].fi) <= dot(b[i],a[p[r+1]].fi)) {
            r++;
        }
        pref[l]++; pref[r+1]--;
    }
    rep(i,0,sz(p)) {
        if(i) pref[i] += pref[i-1];
        ans[a[p[i]].se] = pref[i];
    }
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}