#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod = 1e9+7;
ll n,m,k,q;
pll rl[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>m >>k >>q;
    for(int i=0;i<q;i++) {
        cin >>rl[i].se >> rl[i].fi;
    }
    sort(rl,rl+q);
    vector<ll> len;
    ll end=0;
    ll bebas=n;
    for(int i=0;i<q;i++) {
        if(rl[i].se>end) {
            len.push_back(rl[i].fi-rl[i].se+1);
            bebas -= rl[i].fi-rl[i].se+1;
            end = rl[i].fi;
        }
    }
    ll ans = fastexpo(m,bebas);
    for(ll leni : len) {
        ll temp = fastexpo(m,leni)-fastexpo(m-k,leni);
        temp = (temp+mod)%mod;
        ans = ans*temp%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}