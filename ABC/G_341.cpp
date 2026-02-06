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

const int mxn=2e5;
int n;
ll pref[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        int a; cin >>a;
        pref[i] = pref[i-1]+a;
    }
    vector<double> v(n+1);
    int l=n-1;
    stack<int> st;
    st.push(n);
    auto get = [&](int i, int j) -> double {
        return 1.0*(pref[j]-pref[i])/(j-i);
    };
    while(l>=0) {
        int top = st.top(); st.pop();
        while(sz(st) && get(l,st.top())>get(l,top)) {
            top = st.top(); st.pop();
        }
        v[l+1] = get(l,top);
        st.push(top);
        st.push(l);
        l--;
    }
    rep(i,1,n+1) {
        cout <<fixed <<setprecision(8) <<v[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}