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
int pos[26],gr[26];
char c1,c2;

void solve() {
    cin >>c1 >>c2;
    if(gr[c1-'a']!=gr[c2-'a']) {
        cout <<"different\n";
    } else {
        cout <<abs(pos[c1-'a']-pos[c2-'a']) <<"\n";
    }
}

void init() {
    string a = "qwertyuiop";
    int id = 0;
    rep(i,0,sz(a)) {
        char c = a[i];
        gr[c-'a'] = id;
        pos[c-'a'] = i;
    }
    id++;
    a = "asdfghjkl";
    rep(i,0,sz(a)) {
        char c = a[i];
        gr[c-'a'] = id;
        pos[c-'a'] = i;
    }
    id++;
    a = "zxcvbnm";
    rep(i,0,sz(a)) {
        char c = a[i];
        gr[c-'a'] = id;
        pos[c-'a'] = i;
    }
    id++;        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}