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
double x,a,b;
string s,t;

void solve() {
    cin >>x >>a >>b;
    cin >>s >>t;
    rep(i,0,x) {
        double hp = a;
        bool ok = 0;
        rep(j,0,x) {
            int cur = (s[j]=='#')?0:1;
            bool same = (s[j]==t[j]);
            if(j==i) {
                same = !same;
            }
            hp += b;
            if(same) {
                if(cur) {
                    hp /= 2.0;
                } else {
                    hp -= b*3;
                }
            }
            if(hp<1) {
                cout <<j+1 <<endl;
                ok = 1;
                break;
            }
        }
        if(!ok) {
            cout <<"-1" <<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}