#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i= a; i < (b);i++)
#define per(i,a,b) for(int i= a; i > (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

void solve() {
    int N, A, B; cin >> N >> A >> B;
    assert(A + B != N - 1);
    if (A + B > N - 1) {
        cout << A + B - N << '\n';
    } else if (A + B < N - 1) {
        cout << N - A - B - 2 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}