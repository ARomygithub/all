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

const int mxn=1e5,mxa=22000;
int n,t;
string ans[mxa+1];

void solve() {
    cin >>n;
    cout <<ans[n] <<"\n";
}

string getSum(string a, string b) {
    string ret="";
    int c=0;
    if(sz(a)>sz(b)) swap(a,b);
    for(int i=0;i<min(sz(a),sz(b));i++) {
        int temp = a[sz(a)-1-i]-'0'+b[sz(b)-1-i]-'0'+c;
        ret +=(char)('0'+(temp%10));
        c = temp/10;
    }
    for(int i=sz(a);i<sz(b);i++) {
        int temp = b[sz(b)-i-1]-'0'+c;
        ret +=(char)('0'+(temp%10));
        c = temp/10;
    }
    while(c) {
        ret +=(char)('0'+(c%10));
        c /=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

void init() {
    ans[1] = "1";
    ans[2] = "2";
    for(int i=3;i<=mxa;i++) {
        ans[i] = getSum(ans[i-1],ans[i-2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}