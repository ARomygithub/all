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

void solve() {
    string s;
    cin >>s;
    int n = s.length();
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            set<char> vc;
            vc.insert(s[i-1]);
            if(i+1<n) vc.insert(s[i+1]);
            if(vc.find('a')==vc.end()) {
                s[i] = 'a';
            } else if(vc.find('b')==vc.end()) {
                s[i] = 'b';
            } else if(vc.find('c')==vc.end()) {
                s[i] = 'c';
            }
        }
    }
    cout <<s <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}