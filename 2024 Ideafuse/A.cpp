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

const int mxn=1e2;
int n,m;

void solve() {
    cin >>n >>m;
    int ans = 0;
    rep(i1,0,n+1) {
        rep(i2,i1+2,n+1) {
            if((i1+i2)%2) {
                continue;
            }
            rep(j1,0,m+1) {
                rep(j2,j1+2,m+1) {
                    if((j1+j2)%2) {
                        continue;
                    }
                    int ab = i2-i1;
                    int bd = j2-j1;
                    if(ab<=bd && bd<=ab*2) {
                        ans++;
                    }
                }
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}