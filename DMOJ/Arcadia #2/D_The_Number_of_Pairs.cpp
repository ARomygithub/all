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

const int mxn=2e7;
int c,d,x,t;
// vi dv[mxn+1];
int fp[mxn+1];
int mct[mxn+1];
// map<int,int> mct;

int ct(int mn) {
    if(mn==1) return 0;
    if(mct[mn]>0) return mct[mn];
    int j = mn/fp[mn];
    int cur = ct(j) + (fp[j]!=fp[mn]);
    mct[mn] = cur;
    return cur;
}

void solve() {
    cin >>c >>d >>x;
    ll ans = 0;
    int r = (-d)%c;
    r = (c+r)%c;
    for(ll i=1;i*i<=x;i++) {
        if((x%i)==0) {
            int g = i, h = x/g;
            if((h%c) == r) {
                int mn = (h+d)/c;
                ans += (1<<ct(mn));
            }
            if(g!=h) {
                swap(g,h);
                if((h%c) == r) {
                    int mn = (h+d)/c;
                    ans += (1<<ct(mn));
                }                
            }
        }
    }
    cout <<ans <<"\n";
}

void init() {
    fp[1] = 1;
    bitset<mxn+1> iscomp;
    rep(i,2,mxn+1) {
        // cout <<i <<endl;
        if(!iscomp[i]) {
            fp[i] = i;
            mct[i] = 1;
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
    // rep(i,2,mxn+1) {
    //     if(ct[i]==0) {
    //         int j = i/fp[i];
    //         int cur = ct[j] + (fp[j]!=fp[i]);
    //         ct[i] = cur;
    //     }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}