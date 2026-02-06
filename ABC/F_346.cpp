#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
ll n;
string s,t;

void solve() {
    cin >>n;
    cin >>s; 
    cin >>t;
    set<int> st,tt;
    rep(i,0,sz(s)) {
        st.insert(s[i]-'a');
    }
    rep(i,0,sz(t)) {
        tt.insert(t[i]-'a');
    }
    for(auto tti: tt) {
        if(st.find(tti)==st.end()) {
            cout <<"0\n";
            return;
        }
    }
    vector idx(26, vector<int>());
    rep(i,0,sz(s)) {
        idx[s[i]-'a'].push_back(i);
    }
    ll l = 1,r=1ll*n*sz(s)/(1ll*sz(t));
    ll ans = 0;
    while(l<=r) {
        ll mid = (l+r)/2;
        pll u = {0,0};
        // cout <<"mid " <<mid <<endl;
        rep(i,0,sz(t)) {
            ll ki = mid;
            vector<int>& temp = idx[t[i]-'a'];
            auto it = upper_bound(temp.begin(),temp.end(),u.se);
            ll p = 0;
            if(i==0 && t[i]==s[0]) {
                ki--;
                it = temp.begin();
            } else {
                ki--;
                if(it==temp.end()) {
                    it = temp.begin();
                    p++;
                }
                u.se = *it;
            }
            if(ki==0) {
                u = {u.fi+p,u.se};
                continue;
            }
            // cout <<ki <<endl;
            // cout <<sz(idx[t[i]-'a']) <<endl;
            p += ki/sz(idx[t[i]-'a']);
            ll res = ki%(sz(idx[t[i]-'a']));
            int pos = it-temp.begin();
            // cout <<"pos " <<pos <<endl;
            pos += res;
            // cout <<pos <<endl;
            if(pos>=sz(temp)) {
                p++;
                pos -=sz(temp);
            }
            // cout <<p <<" " <<pos <<endl;
            u = {u.fi+p, temp[pos]};
            if(u.fi>=n) break;
        }
        if(u.fi>=n) {
            r = mid-1;
        } else {
            ans = mid;
            l = mid+1;
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