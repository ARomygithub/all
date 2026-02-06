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
int n;
vector<int> idx[11];

void solve() {
    cin >>n;
    rep(i,0,n) {
        int a; cin >>a;
        idx[a].push_back(i);
    }
    vector<int> ff(n,n);
    rep(d,0,5) {
        rep(i,1,11) {
            if(i+d*2>10) break;
            for(int ii: idx[i]) {
                auto it = upper_bound(idx[i+d].begin(),idx[i+d].end(),ii);
                if(it==idx[i+d].end()) {
                    break;
                }
                int ii2 = *it;
                auto it2 = upper_bound(idx[i+d*2].begin(),idx[i+d*2].end(),ii2);
                if(it2==idx[i+d*2].end()) {
                    break;
                }
                min_self(ff[ii], *it2);
            }
            for(int ii: idx[i+d*2]) {
                auto it = upper_bound(idx[i+d].begin(),idx[i+d].end(),ii);
                if(it==idx[i+d].end()) {
                    break;
                }
                int ii2 = *it;
                auto it2 = upper_bound(idx[i].begin(),idx[i].end(),ii2);
                if(it2==idx[i].end()) {
                    break;
                }
                min_self(ff[ii], *it2);                
            }
        }
    }
    ll ans = 1ll*n*(n+1)/2;
    vector<int> suf(n,n);
    suf[n-1] = ff[n-1];
    per(i,n-2,-1) {
        suf[i] = min(suf[i+1],ff[i]);
    }
    rep(i,0,n) {
        // cout <<i <<" " <<ff[i] <<"\n";
        ans -= suf[i]-i;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}