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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e3,mxa=1e9;
const ll mod=998244353;
int n,m;
bool b[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>m;
    int ct0 = 0;
    rep(i,0,n) {
        cin >>b[i];
        ct0 += !b[i];
    }
    if(n-ct0 > m+1) {
        cout <<"0\n";
        return;
    }
    if(m==0) {
        bool flag=1;
        flag &=b[0];
        rep(i,1,n) {
            flag &=(!b[i]);
        }
        if(flag) {
            cout <<"1\n";
        } else {
            cout <<"0\n";
        }
        return;
    }
    if(m>=n-1) {
        cout <<fastexpo(m,ct0) <<"\n";
    } else {
        int ct1 = 0;
        rep(i,0,m+1) {
            ct1 +=b[i];
        }
        ll ans = fastexpo(m, m+1-ct1);
        if(ct1==m+1) {

        } else {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}