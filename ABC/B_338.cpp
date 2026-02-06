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

const int mxn=1e5;
int n;
string s;
int ct[26];

void solve() {
    cin >>s;
    n = s.length();
    rep(i,0,n) {
        ct[s[i]-'a']++;
    }
    char c = 'a';
    int cti=ct[0];
    rep(i,1,26) {
        if(ct[i]>cti) {
            cti = ct[i];
            c = (char)('a'+i);
        }
    }
    cout <<c <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}