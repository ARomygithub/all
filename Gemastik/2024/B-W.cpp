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

const int mxn=1e5;
string s;
vector<vector<string>> tbl1,tbl2;

pii getC(int i,int j) {
    string tmp = tbl1[i][j];
    tmp = tbl2[tmp[0]-'A'][tmp[1]-'A'];
    return {tmp[0]-'A', tmp[1]-'A'};
}

string getInv(int a1, int a2) {
    rep(i,0,4) {
        rep(j,0,4) {
            if(getC(i,j) == (pii){a1,a2}) {
                string ret = "";
                ret += (char)('A'+i);
                ret += (char)('A'+j);
                return ret;
            }
        }
    }
    return "";
}

void solve() {
    cin >>s;
    tbl1 = {
        {"AB","DC","CC","CB"},
        {"CA", "DA", "CD", "DD"},
        {"BC", "AA", "BA", "DB"},
        {"BD", "AD", "BB", "AC"}
    };
    tbl2 = {
        {"CD", "BB", "AC", "CC"},
        {"CB", "DB", "AD", "DD"},
        {"DA", "DC", "BC", "BD"},
        {"AA", "BA", "CA", "AB"}
    };
    string res = "";
    for(int i=0;i<sz(s);i+=2) {
        res += getInv(s[i]-'A',s[i+1]-'A');
    }
    cout <<res <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}