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

const int mxn=24;
int n;
string ed[mxn];

void solve() {
    cin >>n;
    set<int> sf, ss;
    rep(i,0,n) {
        cin >>ed[i];
        rep(j,0,n) {
            if(ed[i][j]=='F') {
                sf.insert(i);
                sf.insert(j);
            } else if(ed[i][j]=='S') {
                ss.insert(i);
                ss.insert(j);
            }
        }
    }
    set<int> both, nei;
    rep(i,0,n) {
        if(sf.count(i) && ss.count(i)) {
            both.insert(i);
            sf.erase(i);
            ss.erase(i);
        } else if((!sf.count(i)) && (!ss.count(i))) {
            nei.insert(i);
        }
    }
    int bwh = n - (n*3+3)/4 - 1;
    max_self(bwh, 0);
    char ch = '*';
    set<int> sch;
    if(sz(sf)>=bwh) {
        ch = 'F';
        for(auto it = sf.begin(); sz(sch)<bwh; it++) {
            sch.insert(*it);
        }
    } else if(sz(ss)>=bwh) {
        ch = 'S';
        for(auto it = ss.begin(); sz(sch)<bwh; it++) {
            sch.insert(*it);
        }
    } else {
        ch = 'F';
        assert(sz(nei)>=bwh);
        for(auto it = nei.begin(); sz(sch)<bwh; it++) {
            sch.insert(*it);
        }
    }
    char nch = ch=='F'?'S':'F';
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            if(ed[i][j]=='?') {
                if(sch.count(i) || sch.count(j)) {
                    ed[i][j] = ch;
                } else {
                    ed[i][j] = nch;
                }
            }
        }
    }
    rep(i,0,n) {
        cout <<ed[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}