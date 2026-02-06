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
int n,k,m,t;
string s;

void solve() {
    cin >>n >>k >>m;
    cin >>s;
    set<char> st;
    string ans = "";
    rep(i,0,m) {
        st.insert(s[i]);
        if(sz(st)==k) {
            ans +=s[i];
            st.clear();
        }
    }
    if(sz(ans)<n) {
        cout <<"NO\n";
        rep(i,0,k) {
            if(!st.count((char)('a'+i))) {
                ans +=(char)('a'+i);
                break;
            }
        }
        while(sz(ans)<n) {
            ans +='a';
        }
        cout <<ans <<"\n";
    } else {
        cout <<"YES\n";
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