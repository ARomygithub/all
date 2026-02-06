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

const int mxn=1e5,mxa=1e9;
string s,t;

void solve() {
    cin >>s;
    cin >>t;
    int n = s.length(), m = t.length();
    vector to(n, vector<pii>(26, {1e9,0}));
    vector<pii> last(26, {1e9,0});
    per(i,n-1,-1) {
        rep(j,0,26) {
            to[i][j] = last[j];
        }
        last[s[i]-'a'] = {0,i};
    }
    per(i,n-1,-1) {
        rep(j,0,26) {
            if(to[i][j].fi==mxa && last[j].fi!=mxa) {
                to[i][j] = last[j];
                to[i][j].fi++;
            }
        }
    }
    pii pos = {-1,n-1};
    rep(i,0,m) {
        int cur = pos.se;
        pii diff = to[cur][t[i]-'a'];
        pos.fi += diff.fi;
        pos.se = diff.se;
        if(pos.fi>m) break;
    }
    if(pos.fi>m) {
        cout <<"-1\n";
    } else {
        cout <<pos.fi+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}