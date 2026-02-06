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
int t;
string s;

int ctMin(string& si) {
    // cout <<si <<"\n";
    int a=0,b=0;
    rep(i,0,10) {
        if(a>b+(11-i)/2 || b > a+(10-i)/2) {
            return i;
        }
        if(si[i]=='1') {
            if(i%2) {
                b++;
            } else {
                a++;
            }
        }
    }
    return 10;
}

void solve() {
    cin >>s;
    int ans = 10;
    vector<int> id;
    rep(i,0,sz(s)) {
        if(s[i]=='?') {
            id.push_back(i);
        }
    }
    if(sz(id)) {
        rep(bit,0,1<<sz(id)) {
            string tmp = s;
            rep(j,0,sz(id)) {
                if((bit>>j)&1) {
                    tmp[id[j]] = '1';
                } else {
                    tmp[id[j]] = '0';
                }
            }
            min_self(ans, ctMin(tmp));
        }
    } else {
        min_self(ans, ctMin(s));
    }
    cout <<ans <<"\n";
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