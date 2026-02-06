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
ll a,b,c;

ll euclid(ll ai, ll bi, ll& xi, ll& yi) {
    if(!bi) return xi=1,yi=0, ai;
    ll d = euclid(bi, ai%bi, yi, xi);
    return yi -= ai/bi*xi, d;
}

void solve() {
    cin >>a >>b >>c;
    if((c%a)==0) {
        cout <<(c/a) <<" 0\n";
        return;
    }
    ll d = __gcd(a,b);
    ll n = a/d;
    ll m = b/d;
    ll im,temp;
    euclid(m,n,im,temp);
    ll x,y;
    im = ((im%n)+n)%n;
    y = im*(c/d)%n;
    // y += n*2;
    x = (c-y*b)/a;
    cout <<x <<" " <<y <<"\n";
    // assert(a*x+b*y==c);
    // euclid(a, b, x, y);
    // ll ad = a/__gcd(a,b);
    // if(y>=0) {
    //     ll k = y/ad;
    //     y -= ad*k;
    //     x += b/d * k;
    // } else {
    //     ll k = - (((-y)+ad-1)/ad);
    //     y -= ad*k;
    //     x += b/d * k;
    // }
    // x *= c/d;
    // y *= c/d;
    // cout <<x <<" " <<y <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout <<(-4)/3 <<endl;
    solve();
}