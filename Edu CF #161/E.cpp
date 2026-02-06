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
ll x,t;

void solve() {
    cin >>x;
    int mx=1e9;
    deque<int> dq;
    dq.push_back(mx); mx--;
    int idx=60;
    while(true) {
        if((x>>idx)&1) {
            break;
        } else {
            idx--;
        }
    }
    idx--;
    bool first=1;
    while(idx>=0) {
        if(!first) {
            dq.push_front(mx); mx--;
        }
        if((x>>idx)&1) {
            dq.push_back(mx); mx--;
        }
        first = 0;
        idx--;
    }
    cout <<sz(dq) <<"\n";
    rep(i,0,sz(dq)) {
        cout <<dq[i] <<" \n"[i==sz(dq)-1];
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