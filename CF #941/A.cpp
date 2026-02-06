#include <bits/stdc++.h>
using namespace std;
// C E EF F G H

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

const int mxn=2e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    rep(i,0,n) {
        s.insert(a[i]);
    }
    int st = 1;
    for(auto it = (--s.end()); it!=s.begin(); it--) {
        auto it2 = it; it2--;
        int ai = (*it)-(*it2);
        int st_new = -1;
        if(st==0) {
            st_new = (ai==1?1:0);
        } else if(st==1) {
            st_new = 0;
        }
        st = st_new;
    }
    int ai = (*s.begin());
    int st_new = -1;
    if(st==0) {
        st_new = (ai==1?1:0);
    } else if(st==1) {
        st_new = 0;
    }
    st = st_new;    
    if(st) {
        cout <<"Bob\n";
    } else {
        cout <<"Alice\n";
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