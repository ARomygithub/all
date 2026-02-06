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

const int mxn=1e2;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
int n,m,x,y;
string s[mxn], t;

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]!='#';
}

void solve() {
    cin >>n >>m >>x >>y; x--,y--;
    rep(i,0,n) {
        cin >>s[i];
    }
    cin >>t;
    map<char,int> mp;
    mp['U'] = 0;
    mp['R'] = 1;
    mp['D'] = 2;
    mp['L'] = 3;
    set<pii> st;
    if(s[x][y]=='@') {
        st.insert({x,y});
    }
    rep(i,0,sz(t)) {
        int k = mp[t[i]];
        int ii = x+di[k], jj=y+dj[k];
        if(e(ii,jj)) {
            x = ii, y = jj;
            if(s[x][y]=='@') {
                st.insert({x,y});
            }
        }
    }
    cout <<x+1 <<" " <<y+1 <<" " <<sz(st) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}