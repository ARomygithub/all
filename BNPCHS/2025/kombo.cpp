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
int n,m;
string s;

struct Nd {
    Nd* to[26];
    bool en = 0;
    Nd* go(char c) {
        int i = c-'a';
        if(!to[i]) {
            to[i] = new Nd();
        }
        return to[i];
    }
};

void solve() {
    cin >>n >>m;
    cin >>s;
    Nd* r = new Nd();
    rep(i,0,m) {
        string sc; cin >>sc;
        Nd* u = r;
        rep(j,0,sz(sc)) {
            u = u->go(sc[j]);
        }
        u->en = 1;
    }
    int ans = 0;
    Nd* u = r;
    rep(i,0,sz(s)) {
        int id = s[i]-'a';
        if(u->to[id]) {
            u = u->to[id];
        } else {
            u = r;
            if(u->to[id]) {
                u = u->to[id];
            }
        }
        if(u->en) {
            ans++;
            u = r;
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