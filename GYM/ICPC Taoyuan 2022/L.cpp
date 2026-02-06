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

const int mxn=1e5;
const string cmds[10] =
    { "CCC", "ACG", "UGA", "UGC", "UAC"
    , "GCG", "UCC", "AGG", "UGU", "CAC"
    };
const string name[10] = {
    "STOP", "NEXT", "PREV", "INC", "DEC", "OUT", "IN", "BEGIN", "END", "DBG"
};
string code;

string getCmd(int i) {
    per(j,9,-1) {
        if(cmds[j]==code.substr(i,3)) {
            return name[j];
        }
    }
    return "invalid";
}

void solve() {
    // cin >>code;
    // for(int i = 0;i<sz(code);i+=3) {
    //     cout <<getCmd(i) <<" ";
    // }
    // vi v4 = {6, 3, 7, 1, 6, 3, 8, } digit+1: 233432450
    // add 2 {}
    vi v4 = {1, 6, 3, 7, 1, 6, 3, 8, 2, 2, }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}