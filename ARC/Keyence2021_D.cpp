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

const int mxn=8;
int n;

void solve() {
    cin >>n;
    int k = (1<<n)-1;
    // int p = (1<<(n-1))-1;
    if(n==1) {
        cout <<"1\n";
        cout <<"AB\n";
        return;
    }
    vector<int> ct((1<<n),0);
    int id = 1;
    cout <<k <<"\n";
    rep(i,1,k+1) {
        string res((1<<n),'B');
        rep(j,0,sz(res)) {
            if(__builtin_popcount(i&j)%2) {
                res[j] = 'A';
            }
        }
        cout <<res <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}