#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
const ll mod=998244353;
ll p,q;

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
    cin >>p >>q;
    ll iv2 = fastexpo(2ll,mod-2);
    bool isEven=0;
    vector<int> v;
    // ll ct=0;
    for(int i=2;1ll*i*i<=p;i++) {
        if((p%i)==0) {
            // ct++;
            // if(1ll*i*i==p) {
            //     isEven = false;
            // }
            int temp=0;
            while((p%i)==0) {
                temp++;
                p /=i;
            }
            v.push_back(temp);
        }
    }
    if(p>1) {
        v.push_back(1);
    }
    for(auto v1 : v) {
        if((v1%2)==1 && (q%2)==1) {
            isEven = 1;
        }
    }
    ll ans=q%mod;
    bool isQEven = (q%2)==0;
    ll divi =1;
    q %=mod;
    for(auto v1 : v) {
        ll temp = ((v1*q%mod)+1)%mod;
        divi = divi*temp%mod;  
    }
    ans = ans*divi%mod;
    if(!isEven && !isQEven) {
        ans = (ans-1+mod)%mod;
    }
    ans = ans*iv2%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}