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

const int mxn=1e3;
int n,m,t;

void solve() {
    cin >>n >>m;
    vector<bool> vis(m+1,0);
    vis[0] = 1;
    rep(i,0,n) {
        string s; cin >>s;
        int ct = 0;
        rep(j,0,m) {
            ct += (s[j]=='1');
        }
        vector<bool> visn(m+1,0);
        rep(j,0,m+1) {
            if(vis[j]) {
                visn[j] = 1;
                int sm;
                int bwh = abs(ct-j);
                if(j+ct<=m) {
                    sm = j+ct;
                } else {
                    sm = m*2 - (j+ct);
                }
                while(sm>=bwh) {
                    visn[sm] = 1;
                    sm -= 2;
                }
            }
        }
        vis.swap(visn);
    }
    string ans = "";
    int mxi = 0;
    per(i,m,-1) {
        if(vis[i]) {
            mxi = i;
            break;
        }
    }
    rep(i,0,m) {
        if(i<mxi) {
            cout <<"1";
        } else {
            cout <<"0";
        }
    }
    cout <<"\n";
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