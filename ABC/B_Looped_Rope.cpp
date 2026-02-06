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

const int mxn=20;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
int n,m,t;
string s[mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='#';
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    bool ok = 1;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='#') {
                int ct = 0;
                rep(k,0,4) {
                    int ii = i+di[k], jj = j+dj[k];
                    if(e(ii,jj)) {
                        ct++;
                    }
                }
                if(ct!=2 && ct!=4) {
                    ok = 0;
                    break;
                }
            }
        }
    }
    if(ok) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
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