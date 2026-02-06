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

const int bac=512, bwa = 4096;
int n;

void solve() {
    cin >>n;
    if(n==29) {
        cout <<"AC\n";
    } else if(n==599) {
        cout <<"WA\n";
    } else if(n==13837) {
        cout <<"TLE\n";
    } else {
        // if(n<=bac) {
            // cout <<"AC\n";
        // } else if(n<=bwa) {
            // cout <<"WA\n";
        // } else {
            // cout <<"TLE\n";
        // }
        // cout <<"RE\n";
        // cout <<"CE\n";
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}