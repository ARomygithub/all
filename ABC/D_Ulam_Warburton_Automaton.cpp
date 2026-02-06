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

const int mxn=3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
int n,m,t;
string s[mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector ct(n, vi(m,0));
    vector<pii> v;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='#') {
                v.push_back({i,j});
            }
        }
    }
    int ans = 0;
    while(true) {
        ans += sz(v);
        vector<pii> v_new;
        for(auto& [i,j]: v) {
            rep(k,0,4) {
                int ii = i+di[k], jj = j+dj[k];
                if(e(ii,jj)) {
                    ct[ii][jj]++;
                }
            }
        }
        for(auto& [i,j]: v) {
            rep(k,0,4) {
                int ii = i+di[k], jj = j+dj[k];
                if(e(ii,jj) && ct[ii][jj]==1) {
                    v_new.push_back({ii,jj});
                }                
            }
        }
        if(sz(v_new)==0) break;
        v.swap(v_new);
    }
    cout <<ans <<"\n";
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