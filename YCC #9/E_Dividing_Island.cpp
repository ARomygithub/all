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

const int mxn=26;
int a,b,c,d,n,t;
int x[mxn];

void solve() {
    cin >>a >>b >>c >>d >>n;
    // a-z. 
    vi v = {0,1};
    if(a%2) {
        swap(v[0],v[1]);
    }
    rep(i,0,n) {
        cin >>x[i];
    }
    string tmp = "";
    rep(i,0,a+c) {
        tmp += '.';
    }
    int k = 0;
    vector<string> ans(max(b,d), tmp);
    rep(j,0,a+c) {
        int len = j<a ? b: d;
        if(v[j%2]) {
            per(i,len-1,-1) {
                ans[i][j] = (char)('a'+k);
                x[k]--;
                if(x[k]==0) k++;
            }
        } else {
            rep(i,0,len) {
                ans[i][j] = (char)('a'+k);
                x[k]--;
                if(x[k]==0) k++;
            }
        }
    }
    cout <<"YES\n";
    rep(i,0,max(b,d)) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}