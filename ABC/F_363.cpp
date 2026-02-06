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
typedef pair<ll,bool> plb;

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
map<ll,bool> vis, pali;
map<ll,plb> dp;

bool pal(ll x) {
    if(pali.count(x)) return pali[x];
    string s = to_string(x);
    rep(i,0,sz(s)) {
        if(s[i]=='0') {
            pali[x] = 0;
            return false;
        }
    }
    rep(i,0,sz(s)) {
        if(i>sz(s)-1-i) break;
        if(s[i]!=s[sz(s)-1-i]) {
            pali[x] = 0;
            return false;
        }
    }
    pali[x] = 1;
    return true;
}

bool valid(ll x) {
    string s = to_string(x);
    rep(i,0,sz(s)) {
        if(s[i]=='0') return false;
    }
    return true;
}

ll getRev(ll x) {
    if((x%10)==0ll) return -1;
    string s = to_string(x);
    reverse(s.begin(),s.end());
    ll ret = stoll(s);
    return ret;
}

plb getDp(ll ni) {
    if(vis[ni]) return dp[ni];
    vis[ni] = 1;
    if(pal(ni)) {
        dp[ni] = {ni,0};
        return dp[ni];
    }
    for(ll i=2;i*i<=ni;i++) {
        if(!valid(i)) continue;
        if((ni%i)==0ll) {
            // if(pal(i)) {
            //     auto res = getDp(ni/i);
            //     if(res.fi!=-1) {
            //         dp[ni] = {i,0};
            //         return dp[ni];
            //     }
            // }
            ll ir = getRev(i);
            if((ni%(i*ir))==0ll) {
                auto res = getDp(ni/(i*ir));
                if(res.fi!=-1) {
                    dp[ni] = {i, 1};
                    return dp[ni];
                }
            }
        }
    }
    dp[ni] = {-1,0};
    return dp[ni];
}

void solve() {
    cin >>n;
    auto res = getDp(n);
    if(res.fi==-1) {
        cout <<"-1\n";
        return;
    }
    vector<plb> v;
    ll u = n;
    while(true) {
        res = getDp(u);
        v.push_back(res);
        if(res.se) {
            ll ir = getRev(res.fi);
            u /= (res.fi*ir);
        } else {
            u /= res.fi;
        }
        if(u==1ll) break;
    }
    deque<ll> dq;
    per(i,sz(v)-1,-1) {
        if(v[i].se) {
            dq.push_front(v[i].fi);
            ll ir = getRev(v[i].fi);
            dq.push_back(ir);
        } else {
            dq.push_back(v[i].fi);
        }
    }
    string ans = "";
    while(sz(dq)) {
        ll ui = dq.front(); dq.pop_front();
        ans += to_string(ui);
        if(sz(dq)) {
            ans +='*';
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // string temp = "363";
    // cout <<(temp.find('0')) <<"\n";
    solve();
}