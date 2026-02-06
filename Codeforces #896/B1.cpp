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

const int mxn=2e5;
const ll mod=1e15;
int n,t;
int a[mxn],bi[mxn],ci[mxn];

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
    ll sum=0ll;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        sum +=a[i];
    }
    if((sum%n)!=0) {
        cout <<"No\n";
        return;
    }
    ll avg = sum/n;
    int ctAvg=0;
    map<int,int> mpb, mpc;
    int mxb=-1;
    for(int i=0;i<n;i++) {
        if(a[i]==avg) {
            ctAvg++;
        } else {
            ll diff = avg-a[i];
            bool isSwap= (avg<a[i]);
            diff = abs(diff);
            int c=0;
            while((diff%2)==0) {
                c++;
                diff /=2;
            }
            diff++;
            int b=0;
            while((diff%2)==0) {
                b++;
                diff /=2;
            }
            if(diff!=1) {
                cout <<"No\n";
                return;
            }
            if(isSwap) swap(b,c);
            max_self(mxb,b);
            bi[i] =b;
            ci[i] =c;
            mpb[b]++;
            mpc[c]++;
        }
    }
    if(sz(mpb)) {
        // if(avg<fastexpo(2ll,mxb)) {
        //     cout <<"No\n";
        //     return;
        // }
        int mink = 1e9;
        for(auto [k,v]: mpb) {
            min_self(mink, k);
            if(mpc[k]!=v) {
                cout <<"No\n";
                return;
            }
        }
        map<int,int> mpbnew;
        set<int> blm;
        for(int i=0;i<n;i++) {
            if(a[i]==avg) continue;
            if(fastexpo(2ll,bi[i]) >)
        }
        if(ctAvg==1) {
            if(avg<fastexpo(2ll,mink)) {
                cout <<"No\n";
                return;
            }
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}