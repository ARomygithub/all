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
int n;

long double ask(int x1, int y1, int x2, int y2) {
    cout <<"query " <<x1 <<" " <<y1 <<" " <<x2 <<" " <<y2 <<"\n" <<flush;
    long double ret; cin >>ret;
    return ret;
}

void solve() {
    int xq=-1;
    long double lxq=-1;
    for(int i=1;i<=mxn;i+=199) {
        long double ret = ask(i,0,i,mxn);
        if(ret>0.0) {
            xq = i;
            lxq = ret;
            break;
        }
    }
    int xq2=xq + 1;
    long double lxq2 = ask(xq2,0,xq2,mxn);
    ll temp = abs(lxq*lxq - lxq2*lxq2);
    temp /=4;
    int d1 = (int)((temp+1)/2);
    int d2 = (int)((temp-1)/2);
    assert(d1-d2==1);
    int cx = -1;
    if(lxq2>lxq) {
        cx = xq+d1;
    } else {
        cx = xq2-d1;
    }
    int yq=-1;
    long double lyq=-1;
    for(int i=1;i<=mxn;i+=199) {
        long double ret = ask(0,i,mxn,i);
        if(ret>0.0) {
            yq = i;
            lyq = ret;
            break;
        }
    }
    int yq2 = yq+1;
    long double lyq2 = ask(0,yq2,mxn,yq2);
    temp = abs(lyq*lyq - lyq2*lyq2);
    temp /=4;
    d1 = (int)((temp+1)/2);
    d2 = (int)((temp-1)/2);
    int cy = -1;
    if(lyq2>lyq) {
        cy = yq+d1;
    } else {
        cy = yq2-d1;
    }
    long double diam = ask(cx,0,cx,mxn);
    long double diam2 = ask(cx+1,0,cx+1,mxn);
    long double diam3 = ask(cx-1,0,cx-1,mxn);
    if(diam2>diam && diam2>diam3) {
        diam = diam2;
        cx = cx+1;
    } else if(diam3>diam && diam3>diam2) {
        diam = diam3;
        cx = cx-1;
    }
    diam = ask(0,cy,mxn,cy);
    diam2 = ask(0,cy+1,mxn,cy+1);
    diam3 = ask(0,cy-1,mxn,cy-1);
    if(diam2>diam && diam2>diam3) {
        diam = diam2;
        cy = cy+1;
    } else if(diam3>diam && diam3>diam2) {
        diam = diam3;
        cy = cy-1;
    }
    int r = (int)(diam/2.0);
    cout <<"answer " <<cx <<" " <<cy <<" " <<r <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}