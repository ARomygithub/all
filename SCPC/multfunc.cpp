#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=1e7;
int n,t;
int k[mxn+1];
ll g[mxn+1];
bool sieve[mxn+1]; //sieve = komposit

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
    g[1]=1;
    for(int i=2;i<=mxn;i++) {
        if(!sieve[i]) {
            prime.push_back(i);
            k[i] = 1;
            g[i] = 1ll*i*i-i+1;
        }
        for(int j=0;j<sz(prime) && 1ll*i*prime[j]<=mxn;j++) {
            sieve[prime[j]*i] = true;
            if(i%prime[j]==0) {
                k[prime[j]*i] = k[i]+1;
                ll temp = fastexpo(1ll*prime[j],2ll*k[i]+1);
                ll temp1 = temp*prime[j]*prime[j];
                temp++, temp1++;
                ll d = __gcd(temp,temp1);
                temp /=d, temp1 /=d;
                g[i*prime[j]] = temp1*(g[i]/temp);
                break;
            } else {
                k[prime[j]*i] = 1;
                g[prime[j]*i] = g[prime[j]]*g[i];
            }
        }
    }
}

void solve() {
    cin >>n;
    cout <<g[n] <<"\n";
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
