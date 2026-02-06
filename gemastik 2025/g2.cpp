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
int n,b;
vi vh[mxn+1];

void solve() {
    cin >>n >>b;
    rep(i,0,n) {
        int s,h; cin >>s >>h;
        vh[h].push_back(s);
    }
    ll base = 0;
    int deg = 0;
    multiset<int> ms;
    rep(i,1,mxn+1) {
        if(sz(vh[i])) {
            while(deg<i && sz(ms)) {
                auto it = --ms.end();
                base += (*it);
                ms.erase(it);
                deg++;
            }
            rep(j,0,sz(vh[i])) {
                ms.insert(vh[i][j]);
            }
            while(sz(ms)>b) {
                ms.erase(ms.begin());
            }
            deg = i;
        }
    }
    while(sz(ms)) {
        auto it = --ms.end();
        base += (*it);
        ms.erase(it);
    }
    cout <<base <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}