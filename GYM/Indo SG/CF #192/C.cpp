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

const int mxn=1e2;
int n;
string s[mxn];

void solve() {
    cin >>n;
    set<int> sn,sm;
    rep(i,0,n) {
        cin >>s[i];
        rep(j,0,n) {
            if(s[i][j]!='E') {
                sn.insert(i);
                sm.insert(j);
            }
        }
    }
    if(sz(sn)<n && sz(sm)<n) {
        cout <<"-1\n";
    } else if(sz(sn)==n) {
        vector<pii> ans;
        rep(i,0,n) {
            rep(j,0,n) {
                if(s[i][j]!='E') {
                    ans.push_back({i+1,j+1});
                    break;
                }
            }
        }
        rep(i,0,sz(ans)) {
            cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
        }
    } else {
        vector<pii> ans;
        rep(j,0,n) {
            rep(i,0,n) {
                if(s[i][j]!='E') {
                    ans.push_back({i+1,j+1});
                    break;
                }
            }
        }
        rep(i,0,sz(ans)) {
            cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}