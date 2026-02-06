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

const int mxn=2e5;
int n,q;
string s;

void solve() {
    cin >>n;
    cin >>s;
    cin >>q;
    set<int> st;
    rep(i,0,n) {
        if(s[i]=='O') {
            st.insert(i+1);
        }
    }
    while(q--) {
        int k; cin >>k;
        if(st.count(k)) {
            st.erase(k);
        } else {
            st.insert(k);
        }
        int l = n - *(st.begin()) + 1 - sz(st);
        int r = *(--st.end()) - sz(st);
        cout <<min(l,r) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}