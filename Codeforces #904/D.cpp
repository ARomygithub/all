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

const int mxn=1e6;
int n,t;
ll mob[mxn+1];
bool sieve[mxn+1];

ll fastexpo(ll a, ll b) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a);}
        a = (a*a);
        b >>=1;
    }
    return ret;
}

void precalc() {
    vector<int> prime;
    mob[1] = 1;
    for(int i=2;i<=mxn;i++) {
        if(!sieve[i]) {
            prime.push_back(i);
            mob[i] = -1;
        }
        for(int j=0;j<sz(prime) && 1ll*i*prime[j]<=mxn;j++) {
            sieve[prime[j]*i] = true;
            if(i%prime[j]==0) {
                // ll temp=1;
                // ll temp2=i;
                // while((temp2%prime[j])==0) {
                //     temp++;
                //     temp2 /=prime[j];
                // }
                mob[i*prime[j]] = 0;
                break;
            } else {
                mob[prime[j]*i] = mob[i]*mob[prime[j]];
            }
        }
    }    
}

void solve() {
    cin >>n;
    vector<int> ct(n+1,0);
    for(int i=0;i<n;i++) {
        int a; cin >>a;
        ct[a]++;
    }
    vector<bool> belum(n+1,1);
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(ct[i]) {
            for(int j=i*2;j<=n;j+=i) {
                belum[j] = 0;
            }
        }
        if(belum[i]) {
            int atas = n/i;
            ll temp=0;
            vector<ll> cta(atas+1,0), ctb(atas+1,0);
            for(int j=1;j<=atas;j++) {
                for(int k=j;k<=atas;k+=j) {
                    cta[j] +=ct[k*i];
                }
            }
            for(int j=1;j<=atas;j++) {

            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    precalc();
    while(t--) {
        solve();
    }
}

// i,j
// i -> divi++
// eksklusi divi, divi*p
// ct[4]*ct[6]+ct[4]*ct[9]+ct[6]*ct[8]+ct[6]*ct[9]+ct[8]*ct[9]
// minus: ct[4]*ct[8]. Jadi C(9,2)=36-C(2,2)-C(2,2)-C(2,2)-C(3,2)-2*2=26.
// ct[d] -> minus[d*2],minus[d*3]

// ct[2]. jadi ct[4]*ct[6]+ct[6]*ct[8].
// brute force