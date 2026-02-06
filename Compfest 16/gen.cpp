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

const int mxn=1e5,mxs=2e3,mxs2=500;

int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = 2000,m=2000;
    vi a,b;
    int sm = 0;
    while(sm<mxs) {
        int atas = min(20,mxs-sm);
        int cur = rnd(1,atas);
        a.push_back(cur);
        sm += cur;
    }
    n = sz(a);
    sm = 0;
    while(sm<mxs2) {
        int atas = min(20,mxs-sm);
        int cur = rnd(1,atas);
        b.push_back(cur);
        sm += cur;
    }
    m = sz(b);
    cout <<n <<" " <<m <<"\n";
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
    }
    rep(i,0,m) {
        cout <<b[i] <<" \n"[i==m-1];
    }
}