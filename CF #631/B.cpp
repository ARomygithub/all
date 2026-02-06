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

const int mxn=2e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    vector<int> ct(mxn+1,0);
    rep(i,0,n) {
        cin >>a[i];
        ct[a[i]]++;
    }
    int lmin = -1,lmax=-1;
    rep(i,0,n) {
        if(ct[a[i]]==2) {
            max_self(lmin, a[i]);
        }
        max_self(lmax, a[i]);
    }
    if(lmin==-1 || lmax==-1 || lmin+lmax != n) {
        cout <<"0\n";
        return;
    }
    int ans = 0;
    vector<pii> vans;
    vector<int> v1(a,a+n);
    sort(v1.begin(),v1.begin()+lmin);
    sort(v1.begin()+lmin,v1.end());
    bool f1 = 1;
    rep(i,0,lmin) {
        if(i+1 != v1[i]) {
            f1 = 0;
            break;
        }
    }
    rep(i,lmin,n) {
        if(i-lmin+1 != v1[i]) {
            f1 = 0;
            break;
        }
    }
    if(f1) {
        ans++;
        vans.push_back({lmin,lmax});
    }
    if(lmin!=lmax) {
        vector<int> v2(a,a+n);
        sort(v2.begin(),v2.begin()+lmax);
        sort(v2.begin()+lmax,v2.end());
        bool f2 = 1;
        rep(i,0,lmax) {
            if(i+1 != v2[i]) {
                f2 = 0;
                break;
            }
        }
        rep(i,lmax,n) {
            if(i-lmax+1 != v2[i]) {
                f2 = 0;
                break;
            }
        }
        if(f2) {
            ans++;
            vans.push_back({lmax,lmin});
        }
    }
    cout <<ans <<"\n";
    if(ans>0) {
        for(auto [l1,l2]: vans) {
            cout <<l1 <<" " <<l2 <<"\n";
        }
    }
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