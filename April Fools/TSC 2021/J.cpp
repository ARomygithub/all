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

const int mxn=1e5;

int val(string s) {
    int temp = s[0]-'a' + s[1]-'1';
    return (1-(temp%2));
}

void solve() {
    string w1,w2,b1,b2;
    cin >>w1 >>w2 >>b1 >>b2;
    int w = val(w1)+1+val(w2);
    int b = val(b1)+1+val(b2);
    if((b%2)==(w%2)) {
        cout <<"White\n";
    } else {
        cout <<"Black\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}