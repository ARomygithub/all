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
int n;
string s;

void solve() {
    cin >>s;
    n = sz(s);
    int ans = 0;
    rep(i,0,n) {
        int a=0,b=0;
        int mn=0, mx= 0;
        rep(j,i,n) {
            if(s[j]=='?') {
                b++;
                mn--;
                mx++;
            } else if(s[j]=='(') {
                a++;
            } else {
                a--;
            }
            if(a+b<0) break;
            if(mn < -a) {
                mn = -a;
                if(abs(a-b)%2) {
                    mn++;
                }
            }
            if(mn>mx) break;
            bool ok = ((abs(a)%2)==(b%2) && -a>=mn && -a<=mx);
            ans += ok;
            // if(ok) {
            //     cout <<s.substr(i,j-i+1) <<endl;
            // }
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