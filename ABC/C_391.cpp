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

const int mxn=1e6;
int n,q;

void solve() {
    cin >>n >>q;
    vi pos(n);
    iota(all(pos),0);
    vector<set<int>> vs(n);
    rep(i,0,n) {
        vs[i].insert(i);
    }
    int ct = 0;
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int p,h; cin >>p >>h; p--,h--;
            if(sz(vs[pos[p]])==2) {
                ct--;
            }
            vs[pos[p]].erase(p);
            if(sz(vs[h])==1) {
                ct++;
            }
            vs[h].insert(p);
            pos[p] = h;
        } else {
            cout <<ct <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}