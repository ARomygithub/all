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

const int mxn=2e3;
const ll mod=(1ll<<31)-1, mul=233811181;
int n,k,x1;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

string biner(ll x) {
    string ret = "";
    while(x) {
        ret += (char)('0'+(x%2));
        x /= 2;
    }
    reverse(all(ret));
    return ret;
}

void solve() {
    cin >>n >>k >>x1;
    cout <<biner(1635063967) <<endl;
    // rep(i,2,mod) {
    //     if(((mul*i)%mod) == 1) {
    //         cout <<"inv " <<i <<endl;
    //         break;
    //     }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}