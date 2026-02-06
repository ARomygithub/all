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

const int mxn=1e5;
int n,t;
string s;

string getNewS(string si) {
    int idx=-1;
    for(int i=1;i<sz(si);i++) {
        if(si[i]<si[i-1]) {
            idx = i-1;
            break;
        }
    }
    if(idx!=-1) {
        return si.substr(0,idx)+si.substr(idx+1,sz(si)-idx-1);
    } else {
        return si.substr(0,sz(si)-1);
    }
}

void solve() {
    cin >>s;
    int pos; cin >>pos;
    n = s.length();
    int ukr = n;
    while(pos>ukr) {
        pos -=ukr;
        ukr--;
        s = getNewS(s);
    }
    cout <<s[pos-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    // while(t--) {
        solve();
    // }
}