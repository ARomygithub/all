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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n;

void solve() {
    cin >>n;
    vector vs(2, vector(2, set<piii>()));
    rep(i,0,n) {
        int x,y; cin >>x >>y;
        vs[((x%2)+2)%2][(y%2+2)%2].insert({{x,y}, i+1});
    }
    auto isN = [&](set<piii>& s) -> bool {
        return sz(s)==n;
    };
    while(isN(vs[0][0]) || isN(vs[0][1]) || isN(vs[1][0]) || isN(vs[1][1])) {
        vector vs2(2, vector(2, set<piii>()));
        auto add = [&](int x, int y, int i) -> void {
            vs2[(x%2+2)%2][(y%2+2)%2].insert({{x,y},i});
        };
        if(isN(vs[0][0])) {
            for(auto [xy,i]: vs[0][0]) {
                auto [x,y] = xy;
                int xn = x/2, yn=y/2;
                add(xn,yn,i);
            }
        } else if(isN(vs[0][1])) {
            for(auto [xy,i]: vs[0][1]) {
                auto [x,y] = xy;
                int xn = x/2, yn = (y-1)/2;
                add(xn,yn,i);
            }
        } else if(isN(vs[1][0])) {
            for(auto [xy,i]: vs[1][0]) {
                auto [x,y] = xy;
                int xn = (x-1)/2, yn = y/2;
                add(xn,yn,i);
            }
        } else {
            for(auto [xy,i]: vs[1][1]) {
                auto [x,y] = xy;
                int xn = (x-1)/2, yn = (y-1)/2;
                add(xn,yn,i);
            }
        }
        vs.swap(vs2);
    }
    if(sz(vs[0][0])+sz(vs[1][1])>=1 && sz(vs[0][1])+sz(vs[1][0])>=1) {
        cout <<sz(vs[0][0])+sz(vs[1][1]) <<"\n";
        vector<int> ans;
        for(auto [xy,i]: vs[0][0]) {
            ans.push_back(i);
        }
        for(auto [xy,i]: vs[1][1]) {
            ans.push_back(i);
        }
        rep(i,0,sz(ans)) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    } else if(sz(vs[0][0])+sz(vs[1][1])==n) {
        cout <<sz(vs[0][0]) <<"\n";
        vector<int> ans;
        for(auto [xy,i]: vs[0][0]) {
            ans.push_back(i);
        }
        rep(i,0,sz(ans)) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    } else {
        cout <<sz(vs[0][1]) <<"\n";
        vector<int> ans;
        for(auto [xy,i]: vs[0][1]) {
            ans.push_back(i);
        }
        rep(i,0,sz(ans)) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}