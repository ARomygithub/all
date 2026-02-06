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

int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rnd(5,20), m = 100;
    set<pii> sm, sn;
    while(sz(sm)<m) {
        pii cur = {rnd(1,100),rnd(1,100)};
        int k = rnd(5,10);
        rep(j,1,k+1) {
            int mul = rnd(1,10);
            sm.insert({cur.fi*mul,cur.se*mul});
        }
    }
    rep(i,0,n) {
        pii cur = {rnd(1,100),rnd(1,100)};
        sn.insert(cur);
        // int k = rnd(5,10);
        // rep(j,1,k+1) {
        //     sn.insert({cur.fi*j,cur.se*j});
        // }
    }
    n = sz(sn);
    m = sz(sm);
    cout <<m <<" " <<n <<"\n";
    for(auto smi: sm) {
        cout <<smi.fi <<" " <<smi.se <<"\n";
    }
    for(auto sni: sn) {
        cout <<sni.fi <<" " <<sni.se <<"\n";
    }
}