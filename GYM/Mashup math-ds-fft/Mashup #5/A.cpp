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
int da,db;

void solve() {
    cin >>da >>db;
    if(da==db) {
        int a = da*10, b = db*10 + 1;
        cout <<a <<" " <<b <<"\n";
    } else if(da+1==db || (da==9 && db==1)) {
        int a = da*10+9, b = db*10;
        if(db==1) {
            b *= 10;
        }
        cout <<a <<" " <<b <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}