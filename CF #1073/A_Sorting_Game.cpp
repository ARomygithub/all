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
string s;

void solve() {
    cin >>n;
    cin >>s;
    int y = count(all(s),'1');
    vi v1;
    rep(i,0,n-y) {
        if(s[i]=='1') {
            v1.push_back(i);
        }
    }
    if(sz(v1)) {
        cout <<"Alice\n";
        rep(i,n-y,n) {
            if(s[i]=='0') {
                v1.push_back(i);
            }
        }
        cout <<sz(v1) <<"\n";
        rep(i,0,sz(v1)) {
            cout <<v1[i]+1 <<" \n"[i==sz(v1)-1];
        }
    } else {
        cout <<"Bob\n";
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