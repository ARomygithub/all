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
string s,ti;

void solve() {
    cin >>s;
    cin >>ti;
    vi ctt(26,0),cts(26,0);
    rep(i,0,sz(s)) {
        cts[s[i]-'a']++;
    }
    rep(i,0,sz(ti)) {
        ctt[ti[i]-'a']++;
    }
    rep(i,0,26) {
        if(cts[i]>ctt[i]) {
            cout <<"Impossible\n";
            return;
        }
        ctt[i] -= cts[i];
    }
    rep(i,0,sz(s)) {
        rep(j,0,26) {
            if(s[i]-'a' <= j) break;
            while(ctt[j]) {
                cout <<(char)('a'+j);
                ctt[j]--;
            }
        }
        cout <<s[i];
    }
    rep(j,0,26) {
        while(ctt[j]) {
            cout <<(char)('a'+j);
            ctt[j]--;
        }
    }
    cout <<"\n";
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