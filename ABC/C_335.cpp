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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,q;
deque<pii> dq;

void solve() {
    cin >>n >>q;
    rep(i,1,n+1) {
        dq.push_back({i,0});
    }
    rep(i,0,q) {
        int qt; cin >>qt;
        if(qt==1) {
            char c; cin >>c;
            pii h = dq.front();
            if(c=='R') {
                h.fi +=1; 
            } else if(c=='L') {
                h.fi--;
            } else if(c=='U') {
                h.se++;
            } else {
                h.se--;
            }
            dq.push_front(h);
            dq.pop_back();
        } else {
            int p; cin >>p;
            cout <<dq[p-1].fi <<" " <<dq[p-1].se <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}