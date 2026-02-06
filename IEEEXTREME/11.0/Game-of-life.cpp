#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
const int di[8]={-1,-1,0,1,1,1,0,-1}, dj[8]={0,1,1,1,0,-1,-1,-1};
int n,m,c;
template<size_t sz> struct bitset_comparer {
    bool operator() (const bitset<sz> &b1, const bitset<sz> &b2) const {
        return b1.to_string() < b2.to_string();
    }
};
// map<bitset<625>,bitset<625>,bitset_comparer<625>> nxt;
map<bitset<625>,int,bitset_comparer<625>> vis;
vector<bitset<625>> ans;

bool e(int i,int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}

int getBit(int state, int i, int j) {
    return (state>>(m*i+j))&1;
}

bitset<625> nxtFun(bitset<625> state) {
    // if(vis.count(state)) return nxt[state];
    // vector<vector<bool>> v(n,vector<bool>(m,0));
    bitset<625> ret(0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int ct=0;
            for(int k=0;k<8;k++) {
                int ii=(i+di[k]+n)%n,jj=(j+dj[k]+m)%m;
                ct +=state[ii*m+jj];
            }
            if(state[i*m+j] && (ct==2 || ct==3)) {
                ret[i*m+j] = 1;
            } else if(!state[i*m+j] && ct==3) {
                ret[i*m+j] = 1;
            }
        }
    }
    return ret;
}

void solve() {
    cin >>n >>m >>c;
    bitset<625> awal;
    for(int i=0;i<n;i++) {
        string s;
        cin >>s;
        for(int j=0;j<m;j++) {
            awal[i*m+j] = (s[j]=='*');
        }
    }
    // map<bitset<625>,bool> vis2;
    // vis2[awal] = 1;
    vis[awal] = 0;
    ans.push_back(awal);
    int pref=-1;
    for(int i=1;i<=c;i++) {
        awal = nxtFun(awal);
        if(vis.count(awal)) {
            pref = vis[awal];
            int ukr = i-pref;
            int pos = (c-i)%ukr;
            awal = ans[pref+pos];
            break;
        } else {
            vis[awal] = i;
            ans.push_back(awal);
        }
    }
    vector<vector<char>> vc(n,vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            vc[i][j] = awal[i*m+j]?'*':'-';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout <<vc[i][j];
        }
        cout <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}