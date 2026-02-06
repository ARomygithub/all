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

const int mxn=3e5, mxa=3e5;
const ll mod=998244353;
ll iv[mxa+1];
int n,m;
string s;

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
}

void solve() {
    cin >>n >>m;
    cin >>s;
    ll ans3=1;
    for(int i=1;i<n-1;i++) {
        if(s[i]=='?') {
            ans3 = ans3*i%mod;
        }
    }
    if(s[0]=='?') {
        cout <<"0\n";
    } else {
        cout <<ans3 <<"\n";
    }
    for(int i=0;i<m;i++) {
        int pos; char c; cin >>pos >>c; pos--;
        if(pos>0 && s[pos]=='?') {
            ans3 = ans3*iv[pos]%mod;
        }
        if(pos>0 && c=='?') {
            ans3 = ans3*pos%mod;
        }
        s[pos] = c;
        if(s[0]=='?') {
            cout <<"0\n";
        } else {
            cout <<ans3 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    init_fac();
    solve();
}