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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int a,b,t;
pii k,q;

void solve() {
    cin >>a >>b;
    cin >>k.fi >>k.se;
    cin >>q.fi >>q.se;
    set<pii> s;
    int di[8] = {a,a,a*-1,a*-1,b,b,b*-1,b*-1};
    int dj[8] = {b,-1*b,b,-1*b,a,-1*a,a,-1*a};
    rep(i,0,8) {
        pii x;
        x.fi = k.fi+di[i];
        x.se = k.se+dj[i];
        if((abs(x.fi-q.fi)==a && abs(x.se-q.se)==b) || (abs(x.fi-q.fi)==b && abs(x.se-q.se)==a)) {
            s.insert(x);
        }
    }
    cout <<sz(s) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}