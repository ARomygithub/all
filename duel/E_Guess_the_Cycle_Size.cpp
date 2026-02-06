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
int n,t;

pll ask(int a, int b) {
    cout <<"? " <<a <<" " <<b <<"\n" <<flush;
    ll r1,r2; cin >>r1;
    cout <<"? " <<b <<" " <<a <<"\n" <<flush;
    cin >>r2;
    return {r1,r2};
}

void solve() {
    int ct = 0;
    ll tmp = -1;
    // rep(i,1,51) {
    int i = 1;
    rep(j,i+1,51) {
        auto cur = ask(i,j);
        ct++;
        if(cur.fi==-1) {
            if(i==1) {
                cout <<"! " <<j-1 <<"\n" <<flush;
                return;
            }
            break;
        }
        if(cur.fi!=cur.se) {
            cout <<"! " <<cur.fi+cur.se <<"\n" <<flush;
            return;
        }  else {
            tmp = cur.fi+cur.se;
        }
        if(ct==25) break;
    }
    cout <<"! " <<tmp <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    // while(t--) {
        solve();
    // }
}