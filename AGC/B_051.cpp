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

const int mxn=1e5;
int n;

void solve() {
    pii a = {1,0};
    pii b = {0,10};
    pii c = {200,200};
    vector<pii> ans;
    rep(i,0,10) {
        rep(j,0,10) {
            rep(k,0,10) {
                pii temp = {a.fi*i+b.fi*j+c.fi*k,a.se*i+b.se*j+c.se*k};
                ans.push_back(temp);
            }
        }
    }
    cout <<sz(ans) <<"\n";
    for(auto [x,y]: ans) {
        cout <<x <<" " <<y <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}