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

const int mxn=4e3;
int n;
string s[mxn];

bool chk(int szi, int i, int j) {
    rep(i2,0,szi) {
        rep(j2,0,szi) {
            if(((i2+j2)%2)==0 && s[i+i2][j+j2]=='.') {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector bli(n, vector<int>());
    vector blj(n, vector<int>());
    rep(i,0,n) {
        rep(j,0,n) {
            if(s[i][j]=='#') {
                bli[i].push_back(j);
                blj[j].push_back(i);
            }
        }
    }
    vector r(n, vector<int>(n));
    vector d(n, vector<int>(n));
    rep(i,0,n) {
        
    }
    int bts = (n+3)/6;
    per(k,bts,0) {
        int szi = k*2-1;
        map<pii,bool> mp;
        int ats = szi, bwh = n-szi*2;
        rep(i,ats,bwh+1) {
            rep(id,0,sz(bli[i])) {
                int j = bli[i][id];
                if(bli[i][id]+szi*2 > n-szi) break;
                auto it = lower_bound(bli[i].begin(), bli[i].end(), bli[i][id]+szi*2);
                if(it==bli[i].end()) {
                    break;
                } else if((*it)==bli[i][id]+szi*2) {
                    if(chk(szi,i,j) && chk(szi,i,j+szi*2)) {
                        mp[{i, bli[i][id]+szi}] = 1;
                    }
                }
            }
        }
        rep(j,ats,bwh+1) {
            rep(id,0,sz(blj[j])) {
                int i = blj[j][id];
                if(i+szi*2 >n-szi) break;
                auto it = lower_bound(blj[j].begin(), blj[j].end(), i+szi*2);
                if(it==blj[j].end()) {
                    break;
                } else if((*it)==i+szi*2 && mp.count({i+szi,j}) && chk(szi,i,j) && chk(szi,i+szi*2,j)) {
                    cout <<k <<"\n";
                    return;
                }
            }
        }
    }
    cout <<"0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}