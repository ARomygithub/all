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

const int mxn=1e5;
ll l,r,t;
string sd;

void solve() {
    cin >>sd;
    cin >>l >>r;
    ll bagi = 1;
    ll x = 0;
    // cout <<sd.find('.') <<endl;
    // cout <<sd.length() <<endl;
    int id = sd.find('.');
    // cout <<id <<endl;
    if(id<(int)(sd.length()) && id>=0) {
        x = 0;
        rep(i,0,sz(sd)) {
            if(sd[i]=='.') continue;
            x = x*10 + (sd[i]-'0');
        } 
        rep(i,0,(int)(sd.length())-id-1) {
            bagi *= 10;
        }
    } else {
        x = stoll(sd);
    }
    ll dd = __gcd(x,bagi);
    x /= dd;
    bagi /= dd;
    if(bagi*l > x || bagi*r < x) {
        cout <<"-1\n";
        return;
    }
    vector<ll> ans(bagi,l);
    x -= l*bagi;
    rep(i,0,bagi) {
        ll ad = min(x, r-l);
        ans[i] += ad;
        x -= ad;
    }
    cout <<bagi <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}