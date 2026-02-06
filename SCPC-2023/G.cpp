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
int n;

int ask(int x) {
    cout <<"? " <<x <<"\n";
    cout <<flush;
    int z; cin >>z;
    return z;
}

void solve() {
    cin >>n;
    int z1 = ask(1);
    int z2 = ask(2);
    if(n>2) {
        int z3 = ask(3);
        int k = (z1+z3-z2*2)/2;
        cout <<"! " <<k <<"\n";
        cout <<flush;
    } else {
        int ans=0;
        ans += (z1!=0);
        ans += (z2!=0);
        cout <<"! " <<ans <<"\n";
        cout <<flush;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}