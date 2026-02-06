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

const int mxn=1500;
int n,k,t;
using vb = bitset<1501>;
using pbb = pair<vb,vb>;
pbb basis[mxn+1];
bool udh[mxn+1];

void add(vb v, int id) {
    vb vid;
    vid[id] = 1;
    per(i,k,-1) {
        if(v[i]) {
            if(!udh[i]) {
                basis[i] = {v,vid};
                // rep(j,0,n) {
                //     cout <<(int)vid[j];
                // }
                // cout <<"\n";
                udh[i] = 1;
                return;
            } else {
                v ^= basis[i].fi;
                vid ^= basis[i].se;
            }
        }
    }
    // sol
    vi ans;
    rep(i,0,n) {
        if(vid[i]) {
            ans.push_back(i);
        }
    }
    string s = "";
    rep(i,0,n) {
        s +='0';
    }
    rep(i,0,sz(ans)/2) {
        int j = ans[i];
        s[j] = '1';
    }
    rep(i,sz(ans)/2,sz(ans)) {
        int j = ans[i];
        s[j] = '2';
    }
    cout <<s <<"\n";
    exit(0);
}

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        string s;
        cin >>s;
        // s += '1';
        vb v;
        // assert(v[k]);
        rep(i,0,k) {
            if(s[i]=='0') {
                v[i] = 0;
            } else {
                v[i] = 1;
            }
        }
        v[k] = 1;
        add(v,i);
    }
    cout <<"*\n";
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