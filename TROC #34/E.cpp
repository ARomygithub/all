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

const int mxn=1e5,mxa=1e5;
const ll mod=1e9+7;
int n;
int a[mxn], fp[mxa+1];

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
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=0;i+1<n;i++) {
        if((a[n-1]%a[i])!=0) {
            cout <<"-1\n";
            return;
        }
    }
    vector<bool> repr(a[n-1]+1,false);
    set<int> s2;
    for(int i=0;i<n;i++) {
        int u=a[i];
        if(u==1) {
            s2.insert(u);
            continue;
        }
        map<int,int> mp;
        while(u>1) {
            mp[fp[u]]++;
            u /=fp[u];
        }
        for(auto [k,v]: mp) {
            int repi = fastexpo(k,v);
            if(!repr[repi]) {
                repr[repi] = 1;
                s2.insert(a[i]);
                // cout <<a[i] <<"\n";
            }
        }
    }
    set<ll> t;
    for(auto si : s2) {
        set<ll> t2;
        for(auto ti : t) {
            t2.insert(1ll*si*ti/__gcd(ti,1ll*si));
        }
        for(auto ti : t2) {
            t.insert(ti);
        }
        t.insert(si);
    }
    // cout <<sz(t) <<"\n";
    if(sz(t)<=n) {
        if(sz(t)<n) {
            for(int i=0;i<n;i++) {
                if(t.find(a[i])==t.end()) {
                    set<ll> t2;
                    s2.insert(a[i]);
                    for(auto ti : t) {
                        t.insert(ti*a[i]/__gcd(ti,1ll*a[i]));
                    }
                }   
            }
        }
        cout <<sz(s2) <<"\n";
        for(int si : s2) {
            cout <<si <<" ";
        }
        cout <<"\n";
    } else {
        cout <<"-1\n";
    }
}

void init() {
    vector<bool> isPrime(mxa+1,1);
    for(int i=2;i<=mxa;i++) {
        if(isPrime[i]) {
            fp[i] = i;
            for(int j=i*2;j<=mxa;j+=i) {
                isPrime[j] = 0;
                if(fp[j]==0) {
                    fp[j] = i;
                } else {
                    min_self(fp[j],i);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}