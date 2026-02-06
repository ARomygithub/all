#include <bits/stdc++.h>
using namespace std;
// parafrase: https://codeforces.com/gym/102623/problem/M
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=32, mxm=2*mxn;
int n,m;
string g[mxn];
int dp[32][8][1<<8][1<<8];

#define bitAt(x,i) ((x>>i)&1)
#define setAt(x,i,v) (bitAt(x,i) != v? x^(1<<i) : x)

string toMBin(int dec) {
    string ret;
    int ct = m;
    while(ct--) {
        ret += (dec%2) + '0';
        dec/=2;
    }
    // reverse(ret.begin(), ret.end());
    return ret;
} 

int solve(int i, int j, int prvRow, int restrict, int left) {
    debug() <<imie("solve") <<imie(i) <<imie(j) <<imie(toMBin(prvRow)) <<imie(toMBin(restrict)) <<imie(left);
    if(i == n) return restrict == 0? 0 : -1e9;
    if(j == m) return solve(i+1, 0, prvRow, restrict, 0);
    int &ret = dp[i][j][prvRow][restrict];
    if(~ret) return ret;
    if(bitAt(restrict, j) && g[i][j] == '#') return -1e9;
    if(g[i][j]=='#') {
        return ret = solve(i,j+1,setAt(prvRow,j,0), setAt(restrict,j,0),0);
    }
    int newRes = setAt(restrict, j, 0);
    if(j>0) newRes = setAt(newRes, (j-1),0);
    ret = solve(i,j+1,setAt(prvRow,j,1),newRes,1);
    if(!bitAt(restrict,j)) {
        ret = max(ret, 1+ solve(i,j+1,setAt(prvRow,j,0),setAt(restrict,j,!(bitAt(prvRow,j) || left)), 0)); // kasus [i][j] ga tanam.
    }
    return ret;
}

void printPath(int i, int j, int prvRow, int restrict, int left) {
    debug() <<imie("printPath") <<imie(i) <<imie(j) <<imie(toMBin(prvRow)) <<imie(toMBin(restrict)) <<imie(left);
    if(i==n) return;
    if(j==m) {
        return printPath(i+1, 0, prvRow, restrict, 0);
    }
    int ret = solve(i, j, prvRow, restrict, left);
    debug() <<imie(ret);
    if(g[i][j]=='#') {
        printPath(i, j+1, setAt(prvRow, j, 0), setAt(restrict, j, 0), 0);
        return;
    }
    int newRes = setAt(restrict, j, 0);
    if(j>0) newRes = setAt(newRes, (j-1), 0);
    if(ret == solve(i,j+1,setAt(prvRow, j, 1),newRes,1)) {
        g[i][j] = 'O';
        printPath(i,j+1,setAt(prvRow, j, 1), newRes, 1);
        return;
    } else {
        g[i][j] = 'X';
        printPath(i, j+1, setAt(prvRow, j, 0), setAt(restrict, j, !(bitAt(prvRow, j) || left)), 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>g[i];
    }
    memset(dp, -1, sizeof dp);
    printPath(0, 0, 0, 0, 0);
    for(int i=0;i<n;i++) {
        cout <<g[i] <<"\n";
    }
}