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

const int mxn=10;
int n,m,d;
string s[mxn];

void solve() {
    cin >>n >>m >>d;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector<pii> fl;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='.') {
                fl.push_back({i,j});
            }
        }
    }
    int ans = 0;
    rep(i,0,sz(fl)) {
        rep(j,i+1,sz(fl)) {
            auto [x1,y1] = fl[i];
            auto [x2,y2] = fl[j];
            int ct = 0;
            rep(p,0,n) {
                rep(q,0,m) {
                    if(s[p][q]=='.') {
                        if((abs(p-x1)+abs(q-y1)<=d) || (abs(p-x2)+abs(q-y2)<=d)) {
                            ct++;
                        }
                    }
                }
            }
            max_self(ans, ct);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}