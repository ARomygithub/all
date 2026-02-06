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

const ll mod = 1e9+7;
/**
 * @param n_rows The height of the image.
 * @param n_cols The width of the image.
 * @param image Pixels of the image, given row by row from top to bottom. All pixel colors are alphanumeric.
 * @return The total length of wire needed to deploy the network (modulo 10^9+7)
 */
int getCableLength(int n_rows, int n_cols, vector<string> image) {
  // Write your code here
    map<char,vector<int>> mpx;
    map<char,vector<int>> mpy;
    rep(i,0,n_rows) {
        rep(j,0,n_cols) {
            char c = image[i][j];
            mpx[c].push_back(i);
            mpy[c].push_back(j);
        }
    }
    ll ans = 0;
    for(auto [c,vx]: mpx) {
        rep(i,0,sz(vx)) {
            ll temp = 1ll*vx[i]*(i*2+1-sz(vx))%mod;
            ans = (ans+temp)%mod;
        }
    }
    for(auto [c,vy]: mpy) {
        sort(vy.begin(),vy.end());
        rep(i,0,sz(vy)) {
            ll temp = 1ll*vy[i]*(i*2+1-sz(vy))%mod;
            ans = (ans+temp)%mod;
        }
    }
    ans = ans*2%mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}