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
int n,q,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vector<int> state(n+1,0);
    for(int i=1;i<=n;i++) {
        state[i] = (s[i-1]=='1');
    }
    cin >>q;
    vector<int> a(n+1,0);
    for(int i=0;i<q;i++) {
        int b; cin >>b;
        a[b] = 1-a[b];
    }
    int ct=0;
    for(int i=1;i<=n;i++) {
        if(a[i]) {
            for(int j=i;j<=n;j+=i) {
                state[j] = 1-state[j];
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(state[i]) {
            ct++;
            for(int j=i;j<=n;j+=i) {
                state[j] = 1-state[j];
            }
        }
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}