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

const int mxn=2e5;
const ll mod = 998244353;
int n,m;
typedef pair<int,pii> ipii;

void solve() {
    cin >>n >>m;
    vector<ipii> v(m);
    rep(i,0,m) {
        cin >>v[i].se.fi >>v[i].se.se >>v[i].fi;
        v[i].se.fi--; v[i].se.se--;
    }
    set<int> udh;
    sort(v.begin(), v.end());
    ll ans = 1;
    for(int i=0;i<m;) {
        int j = i;
        map<int,int> mp;
        while(j<m && v[j].fi==v[i].fi) {
            // debug() <<imie(v[j]);
            mp[v[j].se.fi]++;
            mp[v[j].se.se]++;
            j++;
        }
        int ct = 0, ctudh=0;
        for(auto [k,val]: mp) {
            ct += (val>1);
            ctudh += udh.count(k);
        }
        if(ct>1) {
            cout <<"0\n";
            return;
        } else if(ct==1) {
            if(sz(mp)>(j-i+1)) {
                cout <<"0\n";
                return;
            }
            bool val1 = 0;
            for(auto [k,val]: mp) {
                if(val>1) {
                    if(udh.count(k)) {
                        ans = 0;
                    } else {
                        udh.insert(k);
                    }
                    val1 = 1;
                } else {
                    if(!udh.count(k)) {
                        ll temp = v[i].fi-sz(udh);
                        if(!val1) {
                            temp--;
                        }
                        ans = ans*temp%mod;
                        // cout <<temp <<endl;
                        udh.insert(k);
                    }
                }
            }
        } else {
            if(sz(mp)>2) {
                cout <<"0\n";
                return;
            }
            ans = ans*(sz(mp)-ctudh)%mod;
            // if(sz(mp)-ctudh>1) {
            //     cout <<(sz(mp)-ctudh) <<endl;
            // }
            rep(ii,1,sz(mp)-ctudh) {
                ans = ans*(v[i].fi-sz(udh)-ii)%mod;
                // cout <<(v[i].fi-sz(udh)-ii) <<endl;
            }
            for(auto [k,val]: mp) {
                udh.insert(k);
            }
        }
        i =j;
    }
    rep(i,sz(udh),n) {
        ans = ans*(n-i)%mod;
        // cout <<(n-i) <<endl;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}