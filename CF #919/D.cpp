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
const ll mxs=1e18;
int n,q,t;

void solve() {
    cin >>n >>q;
    vector<int> v;
    vector<ll> idx,szi;
    rep(i,0,n) {
        int b,x; cin >>b >>x;
        if(b==1) {
            v.push_back(x);
            if(sz(szi)) {
                ll temp = szi.back();
                if(temp<mxs) {
                    idx.push_back(temp+1);
                    szi.push_back(temp+1);
                }
            } else {
                idx.push_back(1);
                szi.push_back(1);
            }
        } else {
            ll temp = szi.back();
            if(temp<mxs) {
                if(mxs/(x+1)>=temp) {
                    temp *=(x+1);
                } else {
                    temp = mxs;
                }
                szi.pop_back();
                szi.push_back(temp);
            }
        }
    }
    vector<int> ans;
    while(q--) {
        ll k; cin >>k;
        while(true) {
            auto it = lower_bound(idx.begin(),idx.end(),k);
            if(it==idx.end()) {
                it--;
                k %=(*it);
            } else if((*it)==k) {
                int idxi = it-idx.begin();
                ans.push_back(v[idxi]);
                break;
            } else {
                it--;
                k %=(*it);
            }
            if(k==0) {
                int idxi = it-idx.begin();
                ans.push_back(v[idxi]);
                break;                
            }
        }
    }
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
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