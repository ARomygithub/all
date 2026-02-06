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

const int mxn=1e5;
string s;

void solve() {
    cin >>s;
    int n = sz(s);
    int ls = -1;
    rep(i,0,n) {
        if(s[i]=='a') {
            ls = i;
        }
    }
    string p = "";
    rep(i,0,n) {
        if(s[i]!='a') {
            p += s[i];
        }
        if(i>=ls) {
            if(n-i-1==sz(p)) {
                bool ok = 1;
                rep(j,i+1,n) {
                    ok = ok && s[j]==p[j-i-1];
                }
                if(ok) {
                    cout <<s.substr(0,i+1) <<"\n";
                    return;
                }
                break;
            }
        }
    }
    cout <<":(\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}