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
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int q,n;
string s;

char ch(char c) {
    if(c>='A' && c<='Z') {
        return (char)(c-'A' + 'a');
    } else {
        return (char)(c-'a' + 'A');
    }
}

void solve() {
    cin >>s;
    n = s.length();
    cin >>q;
    while(q--) {
        ll ki; cin >>ki; ki--;
        ll r = ki/n;
        ll pos = ki%n;
        ll ct = __builtin_popcountll(r);
        if(ct%2) {
            cout <<ch(s[pos]) <<" ";
        } else {
            cout <<s[pos] <<" ";
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}