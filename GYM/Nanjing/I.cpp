#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> cond(m);
    rep(i, 0, m) {
        cin >> cond[i].first >> cond[i].second;
    }
    sort(all(cond));
    
    int itr = 0;
    int val = 0;
    bool poss= 1;
    rep(i, 0, m) {
        if (cond[i].second < cond[i].first - itr) {
            
        }
        else if (cond[i].second == cond[i].first - itr + val) {
            
        }
        else {
            poss = 0;
            break;
        }
        itr = cond[i].first, val = cond[i].second;
    }

    if (poss) cout << "Yes\n"; else cout << "No\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; cin >> tc;
    while(tc--) solve();
}