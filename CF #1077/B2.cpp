#include <bits/stdc++.h>
using namespace std;

#define int long long

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
int x,y,t;
int p=0,q=0,cp=0,cq=0;
int ans = 1e18;

void get(int bit, int& cur, int xi, int yi) {
    if(bit==-1) {
        
        return;
    }
    int bx = (xi>>bit)&1;
    int by = (yi>>bit)&1;
    if(bx && by) {
        int curp = 1<<bit;
        int curq = (1<<bit)-1;
        cp += curp;
        cq += curq;
        if(cur + abs(xi-curp)+abs(yi-curq)<ans) {
            ans = cur + abs(xi-curp)+abs(yi-curq);
            p = cp;
            q = cq;
        }
        cp -= curp;
        cq -= curq;
    } else if(bx) {
        int curp = 1<<bit;
        cp += curp;
        get(bit-1,cur,xi-curp,yi);
        cp -= curp;
        cq += curp;
        // ll 
    } else if(by) {

    }
}

void solve() {
    cin >>x >>y;
    p = 0, q = 0, cp=0, cq=0;
    ans = 1e18;
    int cur = 0;
    get(30,cur,x,y);
    cout <<p <<" " <<q <<"\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}