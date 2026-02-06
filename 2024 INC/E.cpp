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
    int sm = 0;
    vi v;
    rep(i,0,sz(s)) {
        int cur = s[i]-'0';
        while(sz(v)>=2 && ((v[sz(v)-2]+v[sz(v)-1]+cur)%3)==0) {
            v.pop_back();
            sm++;
        }
        v.push_back(cur);
    }
    // cout <<sm <<endl;
    if(sm%2) {
        cout <<"Anda\n";
    } else {
        cout <<"Kamu\n";
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