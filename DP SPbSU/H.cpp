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

const int mxn=1e6;
int n,k;
int s[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>s[i];
    }
    set<int> st;
    rep(i,0,k) {
        int sti; cin >>sti;
        st.insert(sti);
    }
    map<int,int> mp;
    rep(i,0,n) {
        for(auto sti: st) {
            if(mp.count(s[i]-sti)) {
                if(mp.count(s[i])) {
                    max_self(mp[s[i]], mp[s[i]-sti]+1);
                } else {
                    mp[s[i]] = mp[s[i]-sti]+1;
                }
            }
        }
        if(!mp.count(s[i])) {
            mp[s[i]] = 1;
        }
    }
    int ans = 0;
    for(auto [ke,v]: mp) {
        max_self(ans, v);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}