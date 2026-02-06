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
int n,m,t,c,s;

struct Junction {
    double lat, lng;
    void read() {
        cin >>lat >>lng;
    }
};

struct Street {
    int a,b,dir,cost,len;
    void read() {
        cin >>a >>b >>dir >>cost >>len;
    }
};

void solve() {
    cin >>n >>m >>t >>c >>s;
    // n junctions
    vector<Junction> vn(n);
    rep(i,0,n) {
        vn[i].read();
    }
    vector<Street> vm(m);
    rep(i,0,m) {
        vm[i].read();
    }
    int skor = 0;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}