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

const int mxn=1e5;
int n,k,t;
int s[mxn],a[mxn];

void solve() {
    cin >>n >>k >>t;
    rep(i,0,n) {
        cin >>s[i];
    }
    rep(i,0,k) {
        cin >>a[i]; a[i]--;
    }
    if(k==0) {
        cout <<"0\n";
        return;
    }
    sort(a,a+k);
    vector<ll> sm(n+1,0);
    rep(i,1,n+1) {
        sm[i] = sm[i-1]+s[i-1];
    }
    vector<pll> vsp;
    int id = 0;
    for(int i=0;i<n;) {
        while(id<k && i==a[id]) {
            i++;
            id++;
        }
        if(i==n) continue;
        int j=i+1;
        while(j<n && !(id<k && j==a[id])) {
            j++;
        }
        int ind = 1e9;
        if(i>0) {
            min_self(ind, s[i-1]);
        }
        if(j<n) {
            min_self(ind, s[j]);
        }
        pll vspi;
        vspi.fi = sm[j] - sm[i] - 1ll*ind*(j-i);
        vspi.se = max(vspi.fi, 0ll);
        vector<ll> vle(j-i+1,0ll), vri(j-i+1,0ll);
        if(i>0) {
            rep(len,1,j-i+1) {
                vle[len] = vle[len-1];
                max_self(vle[len], sm[i+len]-sm[i]-1ll*s[i-1]*len);
            }
        }
        if(j<n) {
            rep(len,1,j-i+1) {
                vri[len] = vri[len-1];
                max_self(vri[len], sm[j]-sm[j-len]-1ll*s[j]*len);
            }
        }
        rep(len,0,j-i+1) {
            max_self(vspi.se, vle[len]+vri[j-i-len]);
        }
        vsp.push_back(vspi);
        i =j;
    }
    int ct = sz(vsp)+k;
    ll ans = 0;
    rep(i,0,sz(vsp)) {
        ans += vsp[i].se;
    }
    multiset<ll> st;
    rep(i,0,sz(vsp)) {
        st.insert(vsp[i].fi-vsp[i].se);
    }
    while(ct>t) {
        auto it = --st.end();
        ans += *it;
        ct--;
        st.erase(it);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}