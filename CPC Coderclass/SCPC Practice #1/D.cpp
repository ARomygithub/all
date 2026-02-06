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
int x,y,n;

using pic = pair<int,char>;
pair<int,char> ask(int xi, int yi) {
    cout <<"? " <<xi <<" " <<yi <<"\n";
    cout <<flush;
    pic ret;
    cin >>ret.fi >>ret.se;
    return ret;
}

void solve() {
    cin >>x >>y >>n;
    int xl=1,xr=x,yd=1,yu=y;
    while(xl!=xr || yd!=yu) {
        int xm = (xl+xr)/2;
        int ym = (yd+yu)/2;
        auto ret = ask(xm,ym);
        if(ret.fi==1) {
            xl = xm+1; yd=ym+1;
        } else if(ret.fi==2) {
            xr = xm; yd = ym+1;
        } else if(ret.fi==3) {
            xr = xm; yu = ym;
        } else {
            xl = xm+1; yu = ym;
        }
        if(ret.se=='U') {
            yu = min(yu+1,y);
            yd = min(yd+1,y);
        } else if(ret.se=='D') {
            yu = max(yu-1,1);
            yd = max(yd-1,1);
        } else if(ret.se=='L') {
            xl = max(xl-1,1);
            xr = max(xr-1,1);
        } else if(ret.se=='R') {
            xl = min(xl+1,x);
            xr = min(xr+1,x);
        }
    }
    cout <<"! " <<xl <<" " <<yd <<"\n";
    cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}