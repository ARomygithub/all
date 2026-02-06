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

const int mxn=1e5,mxc=26;
int n,m;
string s[mxn];

int getHash(string& si) {
    ll pw = 1;
    ll ret = 0;
    rep(i,0,sz(si)) {
        ret = (ret + (pw*(si[i]-'A')%m))%m ;
        pw = pw*mxc%m;
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    map<int,bool> mp;
    rep(i,0,n) {
        int hs = getHash(s[i]);
        if(mp.count(hs)) {
            cout <<"YA\n";
            return;
        }
        mp[hs] = 1;
    }
    cout <<"TIDAK\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}