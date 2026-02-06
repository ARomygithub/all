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
int n;

int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = 10;
    int k = rnd(1,10);
    vector<int> a(n);
    rep(i,0,n) {
        a[i] = rnd(-10,10);
    }
    int q = rnd(1,20);
    vector<pii> qry(q);
    rep(i,0,q) {
        qry[i].fi = rnd(1,n-k+1);
        qry[i].se = rnd(qry[i].fi+k-1,n);
    }
    cout <<n <<" " <<k <<"\n";
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
    }
    cout <<q <<"\n";
    rep(i,0,q) {
        cout <<qry[i].fi <<" " <<qry[i].se <<"\n";
    }
}