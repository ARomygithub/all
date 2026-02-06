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
int t;
string s;

void solve() {
    cin >>s;
    int sm = 0, ct0=0;
    bool evn = 0;
    rep(i,0,sz(s)) {
        sm += s[i]-'0';
        ct0 += s[i]=='0';
        if(s[i]!='0' && ((s[i]-'0')%2)==0) {
            evn = 1;
        }
    }
    if((sm%3)==0 && (ct0>1 || (ct0==1 && evn))) {
        cout <<"red\n";
    } else {
        cout <<"cyan\n";
    }
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