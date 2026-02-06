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
int n,t;

void solve() {
    cin >>n;
    if(n%2) {
        if(n<=25) {
            cout <<"-1\n";
            return;
        }
        int id = 1;
        vi v(n,0);
        v[1] = id, v[17] = id, v[26] = id;
        id++;
        v[0] = id, v[4]=id;
        id++;
        v[2] = id, v[3] = id;
        id++;
        for(int i=5;i<17;i+=2) {
            v[i] = id, v[i+1]=id;
            id++;
        }
        for(int i=18;i<26;i+=2) {
            v[i] = id, v[i+1] = id;
            id++;
        }
        for(int i=27;i<n;i+=2) {
            v[i] = id, v[i+1] = id;
            id++;
        }
        rep(i,0,sz(v)) {
            cout <<v[i] <<" \n"[i==sz(v)-1];
        }
    } else {
        rep(i,0,n) {
            cout <<(i/2)+1 <<" \n"[i==n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}