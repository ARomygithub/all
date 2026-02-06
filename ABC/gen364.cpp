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

const int mxn=80,mxx=1e4;
int n;

int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = 80;
    int x=rnd(1,mxx), y = rnd(1,mxx);
    vector<int> a(n),b(n);
    rep(i,0,n) {
        a[i] = rnd(1,mxx/10);
    }
    rep(i,0,n) {
        b[i] = rnd(1,mxx/10);
    }
    cout <<n <<" " <<x <<" " <<y <<"\n";
    rep(i,0,n) {
        cout <<a[i] <<" " <<b[i] <<"\n";
    }
}