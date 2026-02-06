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

const int mxn=5e3;
int t;
string s;

void solve() {
    cin >>s;
    int n = sz(s);
    pii pa = {n,n};
    string ans = s;
    ans[n-1] = '0';
    rep(j,0,n-1) {
        int st = -1;
        rep(i,0,j+1) {
            if(s[i]!=s[(n-1)-(j-i)] && s[i]=='1') {
                st = i;
                break;
            }
        }
        if(st!=-1) {
            string tmp = s;
            rep(i,st,j+1) {
                int cur = (s[i]-'0')^(s[(n-1)-(j-i)]-'0');
                tmp[(n-1)-(j-i)] = (char)(cur+'0');
            }
            if(ans<tmp) {
                ans = tmp;
                pa = {st+1,j+1};
            }
        }
    }
    if(ans < s) {
        rep(i,0,n) {
            if(s[i]!=s[n-1]) {
                ans = s;
                pa = {i+1,i+1};
                break;
            }
        }
    }
    cout <<"1 " <<n <<" " <<pa.fi <<" " <<pa.se <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}