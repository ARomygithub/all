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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
string a,b;

void solve() {
    cin >>a;
    cin >>b;
    if(a==b) {
        cout <<"0\n";
        return;
    }
    if(b=="1") {
        cout <<"-1\n";
        return;
    }
    int cta = count(a.begin(),a.end(),'1');
    int ctbi = 0;
    bool f = 1;
    per(i,sz(b)-1,-1) {
        if(f) {
            ctbi += b[i]=='0';
            if(b[i]=='1') {
                f = 0;
            }
        } else {
            ctbi += b[i]=='1';
        }
    }
    if(cta>ctbi) {
        cout <<"2\n";
    } else {
        cout <<ctbi-cta+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}