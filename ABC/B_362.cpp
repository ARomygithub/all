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
struct P {
    typedef int T;
    T x,y;
    explicit P(T x=0, T y=0) : x(x), y(y) {}    
    P operator-(P p) const { return P(x-p.x, y-p.y); }    
    T dot(P p) const { return x*p.x + y*p.y; }    
};
P p[3];

void solve() {
    rep(i,0,3) {
        cin >>p[i].x >>p[i].y;
    }
    rep(i,0,3) {
        int nxt = (i+1)%3, prv = (i+2)%3;
        if((p[nxt]-p[i]).dot(p[prv]-p[i]) == 0) {
            cout <<"Yes\n";
            return;
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}