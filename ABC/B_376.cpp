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

const int mxn=100;
int n,q;

void solve() {
    cin >>n >>q;
    int ans = 0;
    map<char,int> mp;
    mp['L'] = 0;
    mp['R'] = 1;
    vi pos = {1,2};
    rep(i,0,q) {
        char h; int t; cin >>h >>t;
        int id = mp[h];
        if(pos[id]<pos[1-id]) {
            if(t>=pos[id] && t<pos[1-id]) {
                // cout <<t-pos[id] <<"\n";
                ans += (t-pos[id]);
            } else {
                if(t<pos[id]) {
                    ans += (pos[id]-t);
                }
                if(t>pos[1-id]) {
                    ans += (n-t) + pos[id];
                }
            }
        } else {
            if(t>pos[1-id] && t<=pos[id]) {
                ans += (pos[id]-t);
            } else {
                if(t>pos[id]) {
                    ans += (t-pos[id]);
                } else if(t<pos[1-id]) {
                    ans += (n-pos[id]) + t;
                }
            }
        }
        pos[id] = t;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}