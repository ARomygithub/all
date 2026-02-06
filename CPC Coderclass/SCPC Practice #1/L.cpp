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
const ll mod=1e9+7;
int n;
ll m;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a, ll md=mod) {
    return fastexpo(a,md-2,md);
}

void solve() {
    cin >>n >>m;
    // m = 12293389423498234L;
    // rep(i,1e6,1e9+1) {
        // n = i;
        ll ans = m%mod;
        if(n==1) {
            cout <<m%mod <<"\n";
        } else if(n==2) {
            ans %=mod;
            ans = ans*((m-1)%mod)%mod;
            cout <<ans <<"\n";
        } else {
            if((m%mod)==2) {
                ll tmp = (n%2)? 0: 1;
                ans = ans*tmp;
            } else {
                ll tmp1,tmp2;
                int l = (n-1)%2 ? 1:2;
                int r = n-1;
                ll m1 = (m-1)%mod;
                ll ats = (fastexpo(m1,r+2)-fastexpo(m1,l)+mod)%mod;
                ll bwh = (fastexpo(m1,2)-1 + mod)%mod;
                tmp1 = ats*inv(bwh)%mod;
                l = (n-2)%2 ? 1:2;
                r = n-2;
                ats = (fastexpo(m1,r+2)-fastexpo(m1,l)+mod)%mod;
                tmp2 = ats*inv(bwh)%mod;
                // cout <<"tmp1 " <<tmp1 <<"\n";
                // cout <<"tmp2 " <<tmp2 <<"\n";
                ans = ans*((tmp1-tmp2+mod)%mod)%mod;
            }
            cout <<ans <<"\n";
            assert(ans>=0);
        }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}