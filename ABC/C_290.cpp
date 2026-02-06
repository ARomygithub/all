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

const int mxn=3e5;
int n,k;

void solve() {
    cin >>n >>k;
    set<int> s;
    for(int i=0;i<n;i++) {
        int a; cin >>a;
        s.insert(a);
    }
    for(int i=0;i<k;i++) {
        if(s.find(i)==s.end()) {
            cout <<i <<"\n";
            return;
        }
    }
    cout <<k <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}