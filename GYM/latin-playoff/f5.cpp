#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int mxn=2e5;
int n;

void solve() {
    cin >>n;
    int d = 0;
    bool ada0 = 0;
    map<int,int> mp;
    set<pii> s;
    int sg = 0;
    rep(i,0,n) {
        int g,r; cin >>g >>r;
        d = gcd(d, r);
        ada0 = ada0 || (g==0);
        mp[g]++;
        sg += g;
    }
    if(n==1) {
        cout <<"N\n";
        return;
    }
    for(auto [k,v]: mp) {
        s.insert({k,v});
    }
    vi w;
    while(sz(s)) {
        auto [val,occ] = *s.begin(); s.erase(s.begin());
        if(occ%2) {
            w.push_back(val);
            occ = occ/2;
        } else {
            w.push_back(val);
            w.push_back(val);
            occ = (occ-2)/2;
        }
        if(occ>0) {
            if(mp.count(val*2)) {
                s.erase({val*2,mp[val*2]});
            }
            mp[val*2] += occ;
            s.insert({val*2,mp[val*2]});
        }
    }
    bitset<mxn+1> dp;
    dp[0] = 1;
    rep(i,0,sz(w)) {
        dp = dp | (dp<<w[i]);
    }
    rep(i,0,sg+1) {
        if(!ada0 && (i==0 || i==sg)) {
            continue;
        }
        // cout <<i <<" " <<v[id][i] <<endl;
        if(dp[i]==0) continue;
        int dif = abs(sg-i*2);
        if((dif%d)==0) {
            cout <<"Y\n";
            return;
        }
    }
    cout <<"N\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}