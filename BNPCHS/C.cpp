#include <bits/stdc++.h>
using namespace std;

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

const int mxn=3e5;
int n,m;
int a[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    vector<pii> v;
    while(m--) {
        int l,r; cin >>l >>r; l--,r--;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end(), [&](pii a, pii b) {
        if(a.fi!=b.fi) return a.fi<b.fi;
        return a.se>b.se;
    });
    vector<pii> vf;
    for(int i=0;i<sz(v);i++) {
        if(i>0) {
            if(v[i].se > vf.back().se) {
                vf.push_back(v[i]);
            }
        } else {
            vf.push_back(v[i]);
        }
    }
    int ans=0;
    set<int> s;
    int l=vf[0].fi, r=vf[0].se;
    for(int i=l;i<=r;i++) {
        if(s.find(a[i])!=s.end()) {
            a[i] = -1;
            ans++;
        } else {
            s.insert(a[i]);
        }
    }
    for(int i=1;i<sz(vf);i++) {
        if(vf[i].fi<=vf[i-1].se) {
            for(int j=vf[i-1].fi;j<vf[i].fi;j++) {
                if(a[j]!=-1) s.erase(a[j]);
            }
            for(int j=vf[i-1].se+1;j<=vf[i].se;j++) {
                if(s.find(a[j])!=s.end()) {
                    a[j] = -1;
                    ans++;
                } else {
                    s.insert(a[j]);
                }
            }
        } else {
            s.clear();
            for(int j=vf[i].fi;j<=vf[i].se;j++) {
                if(s.find(a[j])!=s.end()) {
                    a[j] = -1;
                    ans++;
                } else {
                    s.insert(a[j]);
                }
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}