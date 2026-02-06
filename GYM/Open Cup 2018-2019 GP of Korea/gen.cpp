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

int rand(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(atoi(argv[1]));
    int n,m;
    n = 10;
    m = rand(5,15);
    vector<pii> lr(n);
    rep(i,0,n) {
        lr[i].fi = rand(0,n-1);
        lr[i].se = rand(lr[i].fi,n-1);
    }
    vector<pii> claim(m);
    rep(i,0,m) {
        int a = rand(0,n-1);
        int b = a;
        while(b==a) {
            b = rand(0,n-1);
        }
        claim[i] = {a,b};
    }
    cout <<n <<" " <<m <<"\n";
    rep(i,0,n) {
        cout <<lr[i].fi+1 <<" " <<lr[i].se+1 <<"\n";
    }
    rep(i,0,m) {
        cout <<claim[i].fi+1 <<" " <<claim[i].se+1 <<"\n";
    }
    return 0;
}