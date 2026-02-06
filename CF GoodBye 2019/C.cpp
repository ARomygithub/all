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
int n,t;
ll a[mxn];

int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}

void solve() {
    cin >>n;
    // n = rnd(1,10000);
    rep(i,0,n) {
        cin >>a[i];
        // a[i] = rnd(1,1e9);
    }
    ll s = 0, x=0;
    rep(i,0,n) {
        s += a[i];
        x ^= a[i];
    }
    ll x1 = 1;
    while(x1<=s) {
        x1 *=2ll;
    }
    if(x1<=1) {
        x1 *=2;
    }
    if(s%2) {
        x1++;
    }
    ll k = ((x^x1)*2 - x1 - s)/2;
    assert((k*2+x1+s)==(x^x1)*2);
    cout <<"3\n";
    cout <<k <<" " <<k <<" " <<x1 <<"\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout <<atoi(argv[1]) <<endl;
    // srand(atoi(argv[1]));
    
    cin >>t;
    // t = rnd(1,100);
    while(t--) {
        solve();
    }
}